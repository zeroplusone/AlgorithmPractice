#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

#define MAXN 500
#define MAXM 1010
#define INF 1000000000
int flow[MAXN][MAXN];
int cap[MAXN][MAXN];
int path[MAXN];
int key[MAXM];
int in[MAXM];
bool v[MAXN];
bool keyv[MAXM];
int all;
queue<int> que;
vector<int> open[MAXM];

bool BFS(int s,int t)
{
	int now;
	bool re=false;
	memset(v,false,sizeof(v));
	
	while(!que.empty())
		que.pop();
		
	v[s]=true;
	que.push(s);
	while(!que.empty())
	{
		now=que.front();
		que.pop();
		if(now==t)
			return true;
		
		for(int i=0;i<all;++i)
		{
			if(cap[now][i]!=0 && !v[i])
			{
				if(cap[now][i]-flow[now][i]>0 || flow[i][now]>0)
				{
					v[i]=true;
					path[i]=now;
					que.push(i);					
				}
			}
		}
	}
	return false;
}

bool DFS(int k,int t)
{
	v[k]=true;
	if(k==t)
		return true;
	for(int i=0;i<all;++i)
	{
		if(v[i])
			continue;
		if(cap[k][i]-flow[k][i]>0 || flow[i][k]>0)
		{
			path[i]=k;
			if(DFS(i,t))
				return true;
		}
	}
	return false;

}

int findflow(int s,int t)
{
	int f=INF;
	for(int i=t,pre;i!=s;i=pre)
	{
		pre=path[i];
		if(cap[pre][i]-flow[pre][i]>0)
			f=min(f,cap[pre][i]-flow[pre][i]);
		else
			f=min(f,flow[i][pre]);
	}
	for(int i=t,pre;i!=s;i=pre)
	{
		pre=path[i];
		if(cap[pre][i]-flow[pre][i]>0)
			flow[pre][i]+=f;		
		else
			flow[i][pre]-=f;
	}
	return f;
}

int maxflow(int s,int t)
{
	int ans=0;
	while(1)
	{
		memset(v,false,sizeof(v));
		//if(!BFS(s,t))
		if(!DFS(s,t))
			break;
		ans+=findflow(s,t);
	}
	return ans;
}

int main()
{
	int i,j,k,pre;
	int m,n,start,end;
	int keyn,buy;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		memset(flow,0,sizeof(flow));
		memset(cap,0,sizeof(cap));
		memset(keyv,false,sizeof(keyv));
		for(i=1;i<=m;++i)
			open[i].clear();
		start=0;	end=n+1;
		all=n+2;
		
		for(i=1;i<=m;++i)
			scanf("%d",&in[i]);
			
		
		for(i=1;i<=n;++i)
		{
			scanf("%d",&keyn);
			for(j=0;j<keyn;++j)
			{			
				scanf("%d",&key[j]);
				if(!keyv[key[j]])
				{
					cap[start][i]+=in[key[j]];
					keyv[key[j]]=true;
				}
				open[key[j]].push_back(i);
				
			}
			scanf("%d",&buy);
			cap[i][end]=buy;
		}
		for(i=1;i<=m;++i)
		{
			for(j=1,pre=0;j<open[i].size();++j,++pre)
				cap[open[i][pre]][open[i][j]]=INF;
		}
		/*for(i=0;i<all;++i)
		{
			for(j=0;j<all;++j)
				printf("%d ",cap[i][j]);
			printf("\n");
		}*/
		printf("%d\n",maxflow(start,end));
	}
	
	
	return 0;
}