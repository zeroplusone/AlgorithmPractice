/******************
Judge   : poj
Problem : 1144-Network
Course  : Course14
discribe:   finding the number of all such critical places
Input   :
			5			//n  ~100
			5 1 2 3 4	//from to to to to
			0			//end
			6			//n
			2 1 3
			5 4 6 2
			0			//end
			0			//all end
Output  :
			1
			2
Solve   : cut vertex[bidirectional]
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;

#define MAXN 110
int low[MAXN],dfn[MAXN];
int dfs_clock;
vector<int> adj[MAXN];
int ans;

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
				flag=1;
		}
		else if(next!=pa)
		{
			low[cur]=min(low[cur],dfn[next]);
		}
	}
	if((child>=2 || pa>=0) && flag)
	{
		ans++;
	}
	return;
}

int s2int(char* ptr)
{
	int ans=0;
	for(int i=0;i<strlen(ptr);++i)
		ans=ans*10+ptr[i]-'0';
	return ans;
}

int main()
{
		char in[MAXN*3];
		char *ptr,token[]=" \n\r";
		int i,from,to,n;
		while(gets(in))
		{
			if(!strcmp(in,"0"))	break;
			n=s2int((char*)in);
			for(i=0;i<=n;++i)
				adj[i].clear();
			dfs_clock=0;	ans=0;
			memset(low,0,sizeof(low));
			memset(dfn,0,sizeof(dfn));
			while(gets(in))
			{
				if(!strcmp(in,"0"))	break;
				ptr=strtok(in,token);
				from=s2int(ptr);
				for(ptr=strtok(NULL,token);ptr;ptr=strtok(NULL,token))
				{
					to=s2int(ptr);
					adj[from].push_back(to);
					adj[to].push_back(from);
				}
			}
			DFS(from,-1);
			printf("%d\n",ans);
		}
		return 0;
}
