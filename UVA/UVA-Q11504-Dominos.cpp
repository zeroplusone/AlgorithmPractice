/******************
Judge   : uva
Problem : 11504 - Dominos
Course  : Course14
discribe:    the minimum number of dominos that must be knocked down by hand in order for all of the dominos to fall.
Input   :
			1	//#case
			3 2	//n(#node 1~n  ~ 100000) m (#road)
			1 2
			2 3
Output  :
			1
Solve   : ssc[bidirectional]
		Kosaraju idea 
		topological high push dowm low -> then count 
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<stack>
using namespace std;

#define MAXN 100100

bool v[MAXN];
vector<int> adj[MAXN];
vector<int> adj2[MAXN];
vector<int> record; 
int n,ans;

void DFS(int cur)
{
	v[cur]=true;
	int next,i;
	for(i=0;i<adj[cur].size();++i)
	{
		next=adj[cur][i];
		if(!v[next])	DFS(next);
	}
	record.push_back(cur);
}

void DFS2(int cur)
{
	v[cur]=true;
	int next,i;
	for(i=0;i<adj[cur].size();++i)
	{
		next=adj[cur][i];	//??adj2
		if(!v[next])	DFS2(next);
	}
}

int Kosaraju()
{
	int i;
	memset(v,false,sizeof(v));	
	for(i=1;i<=n;++i)
	{
		if(!v[i])
			DFS(i);	
	}
	
	memset(v,false,sizeof(v));	
	for(i=record.size()-1;i>=0;--i)
	{
	//printf("%d \n",record[i]);
		if(!v[record[i]])
		{
			DFS2(record[i]);
			ans++;
		}
	}
}

int main()
{
    int m;
    int from,to,d;
    int i;
	int tt;
	int finala;
	scanf("%d",&tt);
	while(tt--)    
	{
		scanf("%d %d",&n,&m);

		for(i=0;i<=n;++i)
		{	
			adj[i].clear();
			adj2[i].clear();
		}
		record.clear();
		while(m--)
		{
			scanf("%d%d",&from,&to);
			adj[from].push_back(to);
			adj2[to].push_back(from);
		}
		ans=0;
		Kosaraju();
		printf("%d\n",ans);
	}
	return 0;
}
