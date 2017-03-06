#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define INF 100100
#define MAXN 1100

int n,mustw;

struct castle
{
	int w,c;
}ca[MAXN];

bool cmp(castle a,castle b)
{
	return a.c>b.c;
}

vector<castle> two,one;

bool canbe(int mid)
{
	int sum=mustw,cost=0,i1,i2,j,len1=one.size(),len2=two.size();
	for(i2=0;i2<len2;++i2)
	{
		//printf("~~~%d %d %d %d\n",sum,two[i2].w,sum+two[i2].w,mid);
		if(sum+two[i2].w<=mid)
		{
			//printf("ya\n");
			sum+=two[i2].w;
		}		
		else
			break;
	}
	for(i1=0;i1<len1;++i1)
	{
		//printf("~~~%d %d %d %d\n",sum,one[i1].w,sum+one[i1].w,mid);
		if(sum+one[i1].w<=mid)
		{
			//printf("ya\n");
			sum+=one[i1].w;
		}		
		else
			break;
	}
	for(j=i1;j<len1;++j)
		cost+=one[j].c;
	for(j=i2;j<len2;++j)
		cost+=two[j].c;
	//printf("~~~%d %d\n",cost,sum);
	if(cost<=sum)	return true;
	else	return false;
}

int binary_search(int L,int R)
{
	int mid;
	while(L<R)
	{
		
		mid=(L+R)>>1;
		//printf("!%d\n",mid);
		if(canbe(mid))
		{
			R=mid;
			
		}
		else
		{
			L=mid+1;			
		}
	}
}

int main()
{
	int T;
	int i;
	int L,R;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		two.clear();
		one.clear();
		L=INF;	R=0;
		for(i=0;i<n;++i)
		{
			scanf("%d%d",&ca[i].w,&ca[i].c);
			R+=ca[i].w;
		}
		mustw=0;
		for(i=0;i<n;++i)
		{
			if(ca[i].c<=R)
			{
				if(ca[i].w==2000)
					two.push_back(ca[i]);				
				else
					one.push_back(ca[i]);			
			}
			else
			{
				mustw+=ca[i].w;
			}	
		}
		sort(two.begin(),two.end(),cmp);
		sort(one.begin(),one.end(),cmp);
		//printf("@@%d\n",mustw);	
		printf("%d\n",binary_search(0,R));
	}
	return 0;
}


