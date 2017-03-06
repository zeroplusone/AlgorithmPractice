/******************
Judge   : uva
Problem : 610 - Street Directions
Course  : Course14
discribe:  convert as many streets as possible into one-way streets. 
Input   :
			7 10	//n(#node 1~n   ~1000) m(#street)
			1 2	
			1 3
			2 4
			3 4
			4 5
			4 6
			5 7
			6 7
			2 5
			3 6
			7 9		//n m
			1 2
			1 3
			1 4
			2 4
			3 4
			4 5
			5 6
			5 7
			7 6
			0 0		//over
Output  :
			1	//case

			1 2
			2 4
			3 1
			3 6
			4 3
			5 2
			5 4
			6 4
			6 7
			7 5
			#	//over
			2

			1 2
			2 4
			3 1
			4 1
			4 3
			4 5
			5 4
			5 6
			6 7
			7 5
			#
Solve   :  cut vertex[bidirectional]
			//give critical bidirection
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;

#define MAXN 1100
int low[MAXN],dfn[MAXN];
int dfs_clock;
vector<int> adj[MAXN];

struct answer
{
	int s,e;
}tmp;

bool v[MAXN][MAXN];

vector<struct answer> ans;
int n,m;
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
			if(low[next]>dfn[cur])
			{
				flag=1;

				tmp.s=cur;	tmp.e=next;	//critical
				ans.push_back(tmp);
				
				tmp.s=next;	tmp.e=cur;
				ans.push_back(tmp);
				
				v[cur][next]=true;
				v[next][cur]=true;
			}
			else
			{
				tmp.s=cur;	tmp.e=next;	//not
				ans.push_back(tmp);
				
				v[cur][next]=true;
				v[next][cur]=true;
			}

		}
		else if(next!=pa)
		{
			low[cur]=min(low[cur],dfn[next]);

				if(!v[cur][next])
				{
					tmp.s=cur;	tmp.e=next;
					ans.push_back(tmp);
					v[cur][next]=true;
					v[next][cur]=true;
				}
			
			//
			
		}
	}
	/*if((child>=2 || pa>=0) && flag)
	{
		ans++;
	}*/
	return;
}

int main()
{
		int i,from,to; 
		int casenum=1;
		while(scanf("%d%d",&n,&m)!=EOF)
		{
			if(n==0 && m==0)	break;
			
			for(i=0;i<=n;++i)
				adj[i].clear();
			ans.clear();
			dfs_clock=0;
			memset(low,0,sizeof(low));
			memset(dfn,0,sizeof(dfn));
			memset(v,false,sizeof(v));
			for(i=0;i<m;++i)
			{
				scanf("%d%d",&from,&to);
				adj[from].push_back(to);
				adj[to].push_back(from);				
			}

			DFS(1,-1);	//must be scc
			
			
			printf("%d\n\n",casenum++);
			for(i=0;i<ans.size();++i)
			{
				printf("%d %d\n",ans[i].s,ans[i].e);
			}
			printf("#\n");
		}
		return 0;
}
