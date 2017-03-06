/******************
Judge   : UVA
Problem : UVA-Q103-Stacking_Boxes.cpp
Course  : coursr9
discribe:  determine the longest nesting string of boxes
			
Input   : 
			5 2	//k(#box) n(dimen)
			3 7
			8 10
			5 2
			9 11
			21 18
			8 6	//k(#box) n(dimen)
			5 2 20 1 30 10
			23 15 7 9 11 3
			40 50 34 24 14 4
			9 10 11 12 13 14
			31 4 18 8 27 17
			44 32 13 19 41 19
			1 2 3 4 5 6
			80 37 47 18 21 9
Output  : 
			5
			3 1 2 4 5
			4
			7 2 5 6
Solve   : LIS
*******************/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;

#define MAXN 50
#define MAXK 15

struct box
{
	int d[MAXK];
	int num;
	bool operator<(const box& p)const
	{
		return d[0]<p.d[0];
	}
}b[MAXN];

int l[MAXN];
int p[MAXN];
int a[MAXN];
int n,k;

bool cmp(int small,int big)
{
	for(int i=0;i<k;++i)
	{
		if(b[small].d[i]<b[big].d[i])
			continue;
		else
			return false;		
	}
	return true;
}

void print(int last)
{
	int many=l[last],find;
	a[many]=b[last].num;	find=p[last];
	for(int i=many-1;i>0;++i)
	{
		a[i]=b[find].num;
		find=p[find];
	}
	printf("%d\n",many);
	for(int i=1;i<=many;++i)
	{
		if(i!=1)	printf(" ");
		printf("%d",a[i]);
	}
	printf("\n");
	

}

int main()
{
	int max,tmp,ans;
	while(scanf("%d %d",&n,&k)!=EOF)
	{		
		ans=0;	l[0]=0;	tmp=-1;
		for(int i=1;i<=n;++i)
		{	
			for(int j=0;j<k;++j)
				scanf("%d",&b[i].d[j]);
			sort(b[i].d,b[i].d+k);
			b[i].num=i;
			l[i]=0;
		}	
		sort(b,b+n);
		for(int i=1;i<=n;++i)
		{
			max=0;
			for(int j=i-1;j>=1;--j)
			{
				if(j>0)
				{
					if(cmp(j,i))
					{
						
						if(l[j]>=max)
						{
							//printf("%d %d ya\n",j,i);
							max=l[j];
							tmp=j;
						}
					}
				}
			}
			l[i]=max+1;
			if(l[i]>l[ans])	ans=i;	
			p[i]=tmp;
			
		}

		int many=l[ans];
		int find;
		a[many]=b[ans].num;	find=p[ans];
		for(int i=many-1;i>0;--i)
		{
			a[i]=b[find].num;
			find=p[find];
		}
		printf("%d\n",many);
		for(int i=1;i<=many;++i)
		{
			if(i!=1)	printf(" ");
			printf("%d",a[i]);
		}
		printf("\n");

	}
	return 0;
}