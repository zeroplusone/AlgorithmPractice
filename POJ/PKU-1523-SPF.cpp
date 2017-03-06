/******************
Judge   : poj
Problem : 1523-SPF
Course  : Course14
discribe:   finding the number of all such critical places
Input   :
			1 2	//road 1~1000
			5 4
			3 1
			3 2
			3 4
			3 5
			0	//over

			1 2
			2 3
			3 4
			4 5
			5 1
			0

			1 2
			2 3
			3 4
			4 6
			6 3
			2 5
			5 1
			0

			0
Output  :
			Network #1
			  SPF node 3 leaves 2 subnets	//cut vertex

			Network #2
			  No SPF nodes

			Network #3
			  SPF node 2 leaves 2 subnets
			  SPF node 3 leaves 2 subnets
Solve   : cut vertex[bidirectional] count seperate part
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

#define MAXN 1100
int dfn[MAXN],low[MAXN];
int dfs_clock;
vector<int> adj[MAXN];

struct answer
{
	int node,num;
	bool operator<(const answer &p)const
	{
		return node==p.node?num<p.num:node<p.node;
	}
}tmp;
vector<struct answer> ans;

void DFS(int cur,int pa)
{
	int child=0;	int flag=0;
	int next;
	low[cur]=dfn[cur]=++dfs_clock;
	for(int i=0;i<adj[cur].size();++i)
	{
		next=adj[cur][i];
		if(!dfn[next])
		{
			child++;
			DFS(next,cur);
			low[cur]=min(low[cur],low[next]);

			if(low[next]>=dfn[cur])
			{
				flag++;
			}
		}
		else if(next!=pa)
		{
			low[cur]=min(low[cur],dfn[next]);
		}
	}
	//printf("%d %d %d\n",cur,child,flag);
	if((child>=2 || pa>=0) && flag)
	{
		tmp.node=cur;
		tmp.num=flag+1;
		ans.push_back(tmp);
	}
	return;
}


int main()
{
    int from,to,d;
    int i;
	int casenum=1;

    while(scanf("%d",&from)!=EOF)
	{
		if(from==0)	break;
		
		for(i=0;i<=MAXN;++i)
			adj[i].clear();
		dfs_clock=0;	ans.clear();
		memset(low,0,sizeof(low));
		memset(dfn,0,sizeof(dfn));
		ans.clear();
		scanf("%d",&to);
		adj[from].push_back(to);
		adj[to].push_back(from);
		while(scanf("%d",&from))
		{
			if(from==0)	break;
			scanf("%d",&to);
			adj[from].push_back(to);
			adj[to].push_back(from);
		}
		
		printf("Network #%d\n",casenum++);
		DFS(to,-1);
		sort(ans.begin(),ans.end());
		if(ans.size()==0)
			printf("  No SPF nodes\n");
		else
		{
			for(i=0;i<ans.size();++i)
			{
				printf("  SPF node %d leaves %d subnets\n",ans[i].node,ans[i].num);
			}
		}
		printf("\n");
	}
	return 0;
}
