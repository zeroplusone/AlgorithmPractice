/******************
Judge   : uva
Problem : 11709 - Trust groups
Course  : Course14
discribe:    finds the minimum number of stable groups that can be created.
( All people appearing in the confidence relations will have appeared in the previous list of P people.)
Input   :
			3 2				//#node ~1000 #road~999000
			McBride, John	//name
			Smith, Peter
			Brown, Anna
			Brown, Anna		//from
			Smith, Peter	//to
			Smith, Peter
			Brown, Anna
			3 2				//#node ~1000 #road~999000
			McBride, John
			Smith, Peter
			Brown, Anna
			Brown, Anna
			Smith, Peter
			McBride, John
			Smith, Peter
			0 0				//over
Output  :
			2			//ssc
			3
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
#include<map>
#include<string>
using namespace std;

#define MAXN 1100
int dfn[MAXN],low[MAXN];
bool onstack[MAXN];
int dfs_clock;
vector<int> adj[MAXN];
stack<int> record;
map<string,int> ch;
int n,ans,all;

int tarjan(int cur,int r)
{
	dfn[cur]=low[cur]=++dfs_clock;
	onstack[cur]=true;
	record.push(cur);
	int next;
	for(int i=0;i<adj[cur].size();++i)
	{
		next=adj[cur][i];
		if(!dfn[next])
		{
			tarjan(next,r);
			low[cur]=min(low[cur],low[next]);
		}
		else if(onstack[next])
			low[cur]=min(low[cur],dfn[next]);
	}
	//printf("%d %d\n",dfn[cur],low[cur]);
	if(dfn[cur]==low[cur])
	{

		int tmp;
		ans++;
		do
		{
			all++;
			tmp=record.top();
			record.pop();
			onstack[tmp]=false;
		}while(cur!=tmp);
	}
}

int main()
{
    int m;
    string from,to;
    int i;
    while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0 && m==0)	break;
		memset(dfn,0,sizeof(dfn));
		memset(onstack,false,sizeof(onstack));
		//memset(low,0,sizeof(low));
		for(i=0;i<=n;++i)
		{
			low[i]=999999;
			adj[i].clear();
		}
		dfs_clock=0;
		ch.clear();
		while(!record.empty())	record.pop();
		getchar();
		for(i=0;i<n;++i)
		{
			getline(cin,from);
			ch[from]=i;
		}
		while(m--)
		{
			getline(cin,from);
			getline(cin,to);
			adj[ch[from]].push_back(ch[to]);		
		}
		ans=0;	all=0;
		for(i=0;i<n;++i)
		{
			if(!dfn[i])
				tarjan(i,i);
		}
		
		printf("%d\n",ans);
	}
}
