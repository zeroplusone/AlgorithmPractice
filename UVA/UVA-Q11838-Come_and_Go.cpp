/******************
Judge   : uva
Problem : 11838 - Come and Go
Course  : Course14
discribe:   judge if it is scc
Input   :
			4 5
			1 2 1
			1 3 2
			2 4 1
			3 4 1
			4 1 2
			3 2
			1 2 2
			1 3 2
			3 2
			1 2 2
			1 3 1
			4 2
			1 2 2
			3 4 2
			0 0
Output  :
			1
			1
			0
			0
Solve   : ssc[directional]
			tarjan
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<stack>
using namespace std;

#define MAXN 2100
int dfn[MAXN],low[MAXN];
int dfs_clock;
vector<int> adj[MAXN];
stack<int> record;
int n,ans,all;
int tarjan(int cur)
{
	dfn[cur]=low[cur]=++dfs_clock;
	record.push(cur);
	int next;
	for(int i=0;i<adj[cur].size();++i)
	{
		next=adj[cur][i];
		if(!dfn[next])
		{
			tarjan(next);
			low[cur]=min(low[cur],low[next]);
		}
		else
			low[cur]=min(low[cur],dfn[next]);
	}
	if(dfn[cur]==low[cur])
	{

		int tmp;
		ans++;
		do
		{
			all++;
			tmp=record.top();
			record.pop();
		}while(cur!=tmp);
	}
}

int main()
{
    int m;
    int from,to,d;
    int i;
    while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0 && m==0)	break;
		memset(dfn,0,sizeof(dfn));
		//memset(low,0,sizeof(low));
		for(i=0;i<=n;++i)
		{
			low[i]=999999;
			adj[i].clear();
		}
		dfs_clock=0;
		while(!record.empty())	record.pop();
		while(m--)
		{
			scanf("%d%d%d",&from,&to,&d);
			if(d==1)
			{
				adj[from].push_back(to);
			}
			else
			{
				adj[from].push_back(to);
				adj[to].push_back(from);
			}
		}
		ans=0;	all=0;
		tarjan(from);
		if(ans==1 && all==n)
			printf("1\n");
		else
			printf("0\n");
	}
}
