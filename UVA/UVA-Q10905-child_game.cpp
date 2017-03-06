#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct game
{
	int num;
	int cmp;
	int big;
	bool operator<(const game& t)const
	{
		return cmp<t.cmp;
	}
}a[51];

int ten(int n)
{
	int ans=1;
	for(int i=0;i<n;++i)
		ans*=10;
	return ans;
}

int main()
{
	int n,count,max,tmp;
	while(scanf("%d",&n)!=EOF)
	{
		max=0;
		if(n==0)
			break;
		for(int i=0;i<n;++i)
		{
			count=0;
			scanf("%d",&a[i].num);
			tmp=a[i].num;
			while(tmp!=0)
			{
				count++;
				tmp/=10;
			}
			a[i].big=count;
			if(count>max)
				max=count;
		}
		for(int j=0;j<n;++j)		
			a[j].cmp=a[j].num*ten(max-a[j].big)+ten(max-a[j].big)-1;
			
		
		sort(a,a+n);
		for(int k=n-1;k>=0;--k)
			printf("%d",a[k].num);
		printf("\n");
		
		
	}
	return 0;
}