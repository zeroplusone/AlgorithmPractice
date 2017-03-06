/******************
Judge   : uva
Problem : 796 - Critical Links
Course  : Course14
discribe: find critical link 
Input   :
			8			//#node
			0 (1) 1		//adj  nocde (#adj) adj node
			1 (3) 2 0 3
			2 (2) 1 3
			3 (3) 1 2 4
			4 (1) 3
			7 (1) 6
			6 (1) 7
			5 (0)

			0		//over
Output  :
			3 critical links
			0 - 1
			3 - 4
			6 - 7

			0 critical links
Solve   :  cut vertex
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

#define MAXN 11000
int low[MAXN],dfn[MAXN];
int dfs_clock;

vector<int> adj[MAXN];

struct answer
{
	int s,e;
	bool operator<(const answer &p)const
	{
		return s==p.s?e<p.e:s<p.s;
	}
}tmp;

vector<struct answer> ans;
int n;

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

				if(cur<next)
				{	
					tmp.s=cur;	
					tmp.e=next;	//critical
				}
				else
				{	
					tmp.s=next;	
					tmp.e=cur;	
				}
				ans.push_back(tmp);
			}

		}
		else if(next!=pa)
		{
			low[cur]=min(low[cur],dfn[next]);	
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
		int i,j,from,to,anum; 
		while(scanf("%d",&n)!=EOF)
		{
			//if(n==0 )	break;
			
			for(i=0;i<=n;++i)
				adj[i].clear();
			ans.clear();
			dfs_clock=0;
			memset(low,0,sizeof(low));
			memset(dfn,0,sizeof(dfn));

			for(i=0;i<n;++i)
			{
				 scanf("%d (%d)", &from, &anum);			
				for(j=0;j<anum;++j)
				{
					scanf("%d",&to);
					adj[from].push_back(to);	
					adj[to].push_back(from);								
				}				
			}

			for(i=0;i<n;++i)	//there may be seperate graph
			{	
				if(!dfn[i])
				{
					DFS(i,-1);
				}					
			}
			sort(ans.begin(),ans.end());
			
			printf("%d critical links\n",ans.size());
			for(i=0;i<ans.size();++i)
			{
				printf("%d - %d\n",ans[i].s,ans[i].e);
			}
			printf("\n");
		}
		return 0;
}
