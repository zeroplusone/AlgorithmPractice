#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define INF 1000100
#define MAXN 1100
int edge[MAXN][MAXN];
int dis[MAXN];
bool v[MAXN];
int ans;
vector<int> s,pn;

void dfs(int n,int now,int sum,int pi)
{
	//printf("!!now %d\n",now);
	
	if(now==n)
	{
		ans=ans>sum+pi?sum+pi:sum;
		return;
	}
	for(int i=now;i<=n;++i)
	{
		if(edge[now][i]!=-1 && !v[i])
		{
			v[now]=true;
			dfs(n,i,sum+edge[now][i],pi);
			v[now]=false;
		}
	}
	return;
}

int main()
{
	int T;
	int i,j,p,d,u,len,n;
	scanf("%d",&T);
	while(T--)
	{
		pn.clear();
		s.clear();
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				edge[i][j]=-1;
		for(i=1;i<=n;++i)
		{
			scanf("%d %d",&p,&d);
			for(j=0;j<d;++j)
			{
				scanf("%d",&u);
				edge[u][i]=p;
			}
			if(d==0)
			{
				s.push_back(i);	
				pn.push_back(p);
			}
				
		}
		len=s.size();
		ans=INF;
/*
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
				printf("%d ",edge[i][j]);
			printf("\n");
		}
*/
		for(i=0;i<len;++i)
		{
			memset(v,false,sizeof(v));
//			printf("@%d\n",s[i]);
			dfs(n,s[i],0,pn[i]);
			//ans=ans>dis[n]+pn[i]?dis[n]+pn[i]:ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}
