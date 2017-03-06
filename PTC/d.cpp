#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

#define MAXN 250
int r[MAXN][MAXN];
int used[MAXN];
int check[100100];
int ans[100100];
int m;
int times;
map<int,int> coun;
int sol[MAXN];
int minans;

void go(int k,int now,int n,int cost)
{
	//printf("~~%d\n",now);
	int i;
	if(k==n-1)
	{	
		sol[k]=now;
		/*for(i=0;i<n;++i)
			{
				printf("%d@",sol[i]);
			}printf("\n");*/
		if(cost>minans)
			return;
		else if(cost<minans)
		{
			memset(ans,0,sizeof(ans));
			minans=cost;
		}
		
			
			times++;
		/*	for(i=0;i<n;++i)
			{
				printf("%d ",sol[i]);
			}printf("\n");*/
			for(i=0;i<m;++i)
			{
				if(coun[check[i]]==0)
				{
					ans[i]++;
				}
			}
		
	}
	else
	{		
		for(i=1;i<=n;++i)
		{
			if(!used[i] && r[now][i] && cost+r[now][i]<=50000)
			{
				used[i]=true;
				coun[now*n+i]++;
				cost+=r[now][i];
				sol[k]=now;
				go(k+1,i,n,cost);
				used[i]=false;
				coun[now*n+i]--;
				cost-=r[now][i];
			}
		}
	}
}

int main()
{
	int c,n;
	int s,t,w;
	int i;
	int final;

	scanf("%d",&c);
	while(c--)
	{
		memset(r,0,sizeof(r));

		memset(ans,false,sizeof(ans));
		coun.clear();
		minans=9999999;
		times=0;
		scanf("%d%d",&n,&m);
		for(i=0;i<m;++i)
		{
			scanf("%d%d%d",&s,&t,&w);
			r[s][t]=r[t][s]=w;
			coun[s*n+t]=0;
			check[i]=s*n+t;
		}
		sol[0]=1;
		for(i=1;i<=n;++i)
		{
			memset(used,false,sizeof(used));
			go(0,i,n,0);
		//	printf("----\n");
		}
		final=0;
		for(i=0;i<m;++i)
		{
			if(ans[i]==times)
				final++;
		}
		printf("%d\n",final);
		
		
	}
	
	return 0;
}