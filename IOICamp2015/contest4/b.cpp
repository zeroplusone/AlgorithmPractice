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
vector<int> s,pn;

void dijkstra(int n,int source)
{

	memset(v,false,sizeof(v));
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
			if(edge[tmp][i]!=-1 && dis[tmp]+edge[tmp][i]<dis[i])
			{
				dis[i]=dis[tmp]+edge[tmp][i];
			}
		}
		visCount++;
	}	
}

int main()
{
	int T;
	int i,j,p,d,u,len,ans,n;
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
//			printf("@%d\n",s[i]);
			dijkstra(n,s[i]);
			ans=ans>dis[n]+pn[i]?dis[n]+pn[i]:ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}
