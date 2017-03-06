/******************
Judge   : PKU
Problem : 2289-Jamie's Contact Groups
Course  : Course11
discribe:  takes the list and organizes it into groups such that each friend appears in only one of those groups and the size of the largest group is minimized.
Input   :
			3 2			//#friend #group  ~1000 ~500
			John 0 1	//name can beling to which books
			Rose 1
			Mary 1
			5 4			//#friend #group
			ACM 1 2 3
			ICPC 0 1
			Asian 0 2 3
			Regional 1 2
			ShangHai 0 2
			0 0			//end

Output	:
			2
			2
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
int n,m;

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

	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0 && m==0)	break;
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		memset(pa,0,sizeof(pa));



		printf("%d\n",Ford(s,t));
	}
	return 0;
}
