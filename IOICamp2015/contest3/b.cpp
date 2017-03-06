#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
#define INF 2000000000
#define MAXN 10100 
int dis[MAXN];
int edge[MAXN][MAXN];
bool v[MAXN];
int ans;

void prim(int n,int source)
{
	for(int i=1;i<=n;++i)
		dis[i]=INF;
	dis[source]=0;
//	v[source]=true;
	int visCount=0,i,tmp;
	while(visCount<n)
	{
		tmp=-1;
		for(i=1;i<=n;++i)
		{
//			printf("!%d %d\n",i,dis[i]);
			if(!v[i])
			{
				if(tmp==-1 || dis[i]<dis[tmp])
					tmp=i;
			}
		}
		v[tmp]=true;
		for(i=1;i<=n;++i)
		{
			if(edge[tmp][i]<dis[i])
			{
				dis[i]=edge[tmp][i];
				ans=ans<dis[i]?dis[i]:ans;
			}
		}
		visCount++;
	}	
	for(i=1;i<=n;++i)
	{
		if(dis[i]==INF)
		{
			ans=-1;
			break;
		}
	}	
}


int main()
{
	int T;
	int n,m;
	int u,vv,w;
	int i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		
		for(i=0;i<=n;++i)
			for(j=0;j<=n;++j)
				edge[i][j]=INF;
		memset(v,false,sizeof(v));
		ans=-1;
		for(i=0;i<m;++i)
		{
			scanf("%d%d%d",&u,&vv,&w);
			edge[u][vv]=w;
		}
		prim(n,1);
		if(ans==-1)
			printf("Earth Worm QAQ\n");
		else
			printf("%d\n",ans);
	}
}

