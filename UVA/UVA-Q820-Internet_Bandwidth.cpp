/******************
Judge   : UVA
Problem : 820 - Internet Bandwidth
Course  : Course11
discribe:  maximun flow
Input   :
			4		//#node(2~100)
			1 4 5	//start end #edge
			1 2 20
			1 3 10
			2 3 5
			2 4 10
			3 4 20
			0		//#node

Output	:
			Network 1
			The bandwidth is 25.
solve:
		maximun flow
*******************/
#include<bits/stdc++.h>
using namespace std;

#define MAXN 110
#define INF 9999999
int cap[MAXN][MAXN];
int flow[MAXN][MAXN];
int pa[MAXN];
bool v[MAXN];
int n;

bool DFS(int cur,int t)
{
	int i;
	v[cur]=true;
	if(cur==t)	return true;
	for(i=1;i<=n;++i)
	{
		if(v[i])	continue;
		if(cap[cur][i]-flow[cur][i]>0 || flow[i][cur]>0)
		{
			pa[i]=cur;
			if(DFS(i,t))	return true;
		}
	}
	return false;
}
int findflow(int s,int t)
{
	int i,pre;
	int f=INF;
	for(i=t;i!=s;i=pa[i])
	{
		pre=pa[i];
		if(cap[pre][i]-flow[pre][i]>0)
			f=min(f,cap[pre][i]-flow[pre][i]);
		else
			f=min(f,flow[i][pre]);
	}
	for(i=t;i!=s;i=pa[i])
	{
		pre=pa[i];
		if(cap[pre][i]-flow[pre][i]>0)
			flow[pre][i]+=f;
		else
			flow[i][pre]-=f;
	}
	return f;
}

int Ford(int s,int t)
{
	int ret=0;
	while(1)
	{
		memset(v,false,sizeof(v));
		if(!DFS(s,t))	break;
		ret+=findflow(s,t);
	}
	return ret;
}

int main()
{
	int s,t,edge;
	int n1,n2,len;
	int casenum=1;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		memset(pa,0,sizeof(pa));
		scanf("%d%d%d",&s,&t,&edge);
		while(edge--)
		{
			scanf("%d%d%d",&n1,&n2,&len);
			cap[n1][n2]+=len;
			cap[n2][n1]+=len;
		}
		printf("Network %d\n",casenum++);
		printf("The bandwidth is %d.\n\n",Ford(s,t));
	}
	return 0;
}
