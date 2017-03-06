/******************
Judge   : uva
Problem : 10594 - Data Flow
Course  : Course16
discribe:print the minimum possible time in a line to send all the data.
Input   :
		
		4 5		//N node M edge  from 1 to n
		1 4 1	//edge start end len
		1 3 3
		3 4 4
		1 2 2
		2 4 5
		20 10	//initial flow   /  capacity for all edge
		4 4
		1 3 3
		3 4 4
		1 2 2
		2 4 5
		20 100
		4 4
		1 3 3
		3 4 4
		1 2 2
		2 4 5
		20 1

Output	:

		80			//minimum possible time   cost*data
		140
		Impossible.
solve:
		MCMF[ bidirectional] no duplicate edge
//The time can be as large as 1015. -->LONG LONG 
*******************/
 /*//TLE
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAXN 105
#define INF 999999
vector<int> adj[MAXN];
long long int flow[MAXN][MAXN];
long long int cost[MAXN][MAXN];
long long int cap[MAXN][MAXN];
long long int dis[MAXN];
bool inq[MAXN];

int pa[MAXN];
int n,m;
long long int d,k,ans;

long long int FindFlow(int s,int t)
{
	int i,j,pre;
	long long int f=INF;
	
	for(i=t;i!=s;i=pa[i])
	{
		//printf("%d ",i);
		pre=pa[i];	
		if(flow[i][pre]>0)
			f=min(f,flow[i][pre]);
		else if(cap[pre][i]-flow[pre][i]>0)
			f=min(f,cap[pre][i]-flow[pre][i]);
		

	}
	//printf("  -> %d ",f);
	for(i=t;i!=s;i=pa[i])
	{
		pre=pa[i];
		if(flow[i][pre]>0)
			flow[i][pre]-=f;
		else if(cap[pre][i]-flow[pre][i]>0)
			flow[pre][i]+=f;
		
	}
	return f;
}	
	
bool SPFA(int s,int t)
{
	int i,now,to;
	queue<int> q;
	while(!q.empty())	q.pop();
	for(i=0;i<=n;++i)
	{
		dis[i]=INF;		inq[i]=false;
	}
	dis[s]=0;	inq[s]=true;	q.push(s);
	while(!q.empty())
	{
		now=q.front();
		inq[now]=false;		q.pop();
		for(i=0;i<adj[now].size();++i)
		{
			to=adj[now][i];
			if(flow[to][now]>0 && dis[now]-cost[to][now]<dis[to])
			{
				dis[to]=dis[now]-cost[to][now];
				pa[to]=now;
				if(!inq[to])
				{
					q.push(to);	inq[to]=true;
				}
			}
			else if(cap[now][to]-flow[now][to]>0 && dis[now]+cost[now][to]<dis[to])
			{
				dis[to]=dis[now]+cost[now][to];
				pa[to]=now;
				if(!inq[to])
				{
					q.push(to);	inq[to]=true;
				}
			}
		}
	}
	return dis[n]!=INF;
}	
	
long long int MCMF(int s,int t)
{
	long long int ff,max_flow=0,min_cost=0;
	while(SPFA(s,t))
	{
		ff=FindFlow(s,t);
		min_cost+=ff*dis[t];	
		max_flow+=ff;
	}
	return max_flow!=d?-1:min_cost;
}

int main()
{
	int s,t;
	long long int l;
	int i,j;	
	
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(i=0;i<=n;++i)
		{
			adj[i].clear();
			for(j=0;j<=n;++j)
			{
				flow[i][j]=0;
				cost[i][j]=0;
			}
		}
		for(i=0;i<m;++i)
		{
			scanf("%d%d%lld",&s,&t,&l);
			adj[s].push_back(t);
			adj[t].push_back(s);
			cost[s][t]=cost[t][s]=l;			
		}
		scanf("%lld %lld",&d,&k);
		
		for(i=0;i<=n;++i)
			for(j=0;j<=n;++j)
				cap[i][j]=k;
		cap[0][1]=d;
		adj[0].push_back(1);
		ans=MCMF(0,n);
		if(ans==-1)
			printf("Impossible.\n");
		else
			printf("%lld\n",ans);
	}
	return 0;
}
*/

 //AC
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAXN 105
#define INF 999999
vector<int> adj[MAXN];
long long int flow[MAXN][MAXN];
long long int cost[MAXN][MAXN];
long long int dis[MAXN];
bool inq[MAXN];
queue<int> q;

int pa[MAXN];
int n,m;
long long int d,k,ans;

long long int FindFlow(int s,int t)
{
	int i,j,pre;
	long long int f=1;
	
	//printf("  -> %d ",f);
	for(i=t;i!=s;i=pa[i])
	{
		pre=pa[i];
		
		//if(flow[pre][i]==0)  *****
			flow[pre][i]+=f;
		//else
			flow[i][pre]-=f;
	}
	return f;
}	
	
bool SPFA(int s,int t)
{
	int i,now,to;
	
	while(!q.empty())	q.pop();
	for(i=0;i<=n;++i)
	{
		dis[i]=INF;		inq[i]=false;
	}
	dis[s]=0;	inq[s]=true;	q.push(s);
	while(!q.empty())
	{
		now=q.front();
		inq[now]=false;		q.pop();
		for(i=0;i<adj[now].size();++i)
		{
			to=adj[now][i];
			if(flow[to][now]>0 && dis[now]-cost[to][now]<dis[to])
			{
				dis[to]=dis[now]-cost[to][now];
				pa[to]=now;
				if(!inq[to])
				{
					q.push(to);	inq[to]=true;
				}
			}
			else if(flow[now][to]==0 && dis[now]+cost[now][to]<dis[to])
			{
				dis[to]=dis[now]+cost[now][to];
				pa[to]=now;
				if(!inq[to])
				{
					q.push(to);	inq[to]=true;
				}
			}
		}
	}
	return dis[n]!=INF;
}	
	
long long int MCMF(int s,int t)
{
	long long int ff,min_cost=0;
	while(d>0 && SPFA(s,t))
	{
		ff=min(d,k);
		FindFlow(s,t);
		min_cost+=ff*dis[t];	
		d-=k;
	}
	return d>0?-1:min_cost;
}

int main()
{
	int s,t;
	long long int l;
	int i,j;	
	
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(i=0;i<=n;++i)
		{
			adj[i].clear();
			for(j=0;j<=n;++j)
			{
				flow[i][j]=0;
				cost[i][j]=0;
			}
		}
		for(i=0;i<m;++i)
		{
			scanf("%d%d%lld",&s,&t,&l);
			adj[s].push_back(t);
			adj[t].push_back(s);
			cost[s][t]=cost[t][s]=l;			
		}
		scanf("%lld %lld",&d,&k);
		
		ans=MCMF(1,n);
		if(ans==-1)
			printf("Impossible.\n");
		else
			printf("%lld\n",ans);
	}
	return 0;
}

