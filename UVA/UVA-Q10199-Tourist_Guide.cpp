/******************
Judge   : uva
Problem : 10199 - Tourist Guide
Course  : Course14
discribe: Those cameras are strategically distributed over the city, in locations that a driver must pass through in order to go from one zone of the city to another. 
			write a program which will tell him where are all the cameras,
Input   :
			6			//node~100
			sugarloaf
			maracana
			copacabana
			ipanema
			corcovado
			lapa
			7			//road
			ipanema copacabana
			copacabana sugarloaf
			ipanema sugarloaf
			maracana lapa
			sugarloaf maracana
			corcovado sugarloaf
			lapa corcovado
			5		//node
			guanabarabay
			downtown
			botanicgarden
			colombo
			sambodromo
			4			//road
			guanabarabay sambodromo
			downtown sambodromo
			sambodromo botanicgarden
			colombo sambodromo
			0			//over
Output  :
			City map #1: 1 camera(s) found
			sugarloaf

			City map #2: 1 camera(s) found
			sambodromo
Solve   :  cut vertex
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

#define MAXN 110
int low[MAXN],dfn[MAXN];
int dfs_clock;

vector<int> adj[MAXN];
map<string,int> ch;
string ch2[MAXN];
vector<string> ans;
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
			if(low[next]>=dfn[cur])
			{
				flag=1;
			}

		}
		else if(next!=pa)
		{
			low[cur]=min(low[cur],dfn[next]);	
		}
	}
	if((child>=2 || pa>=0) && flag)
	{
		ans.push_back(ch2[cur]);
	}
	return;
}

int main()
{
		int i;
		string from,to; 
		int casenum=1;
		while(scanf("%d",&n)!=EOF)
		{
			if(n==0 )	break;
			
			for(i=0;i<=n;++i)
				adj[i].clear();
			ans.clear();
			dfs_clock=0;	ch.clear();
			memset(low,0,sizeof(low));
			memset(dfn,0,sizeof(dfn));

			for(i=0;i<n;++i)
			{
				cin>>from;
				ch[from]=i;
				ch2[i]=from;
			}
			scanf("%d",&m);
			for(i=0;i<m;++i)
			{
				cin>>from>>to;
				adj[ch[from]].push_back(ch[to]);	
				adj[ch[to]].push_back(ch[from]);
			}		
			for(i=0;i<n;++i)	//there may be seperate graph
			{	
				if(!dfn[i])
				{
					DFS(i,-1);
				}					
			}
			sort(ans.begin(),ans.end());
			
			if(casenum!=1)	printf("\n");
			printf("City map #%d: %d camera(s) found\n",casenum++,ans.size());
			for(i=0;i<ans.size();++i)
			{
				cout<<ans[i]<<endl;
			}
		}
		return 0;
}
