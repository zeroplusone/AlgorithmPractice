/******************
Judge   : UVA
Problem : 10779 - Collectors Problem
Course  : Course11
discribe: Bob's friends will only exchange stickers with Bob, and they will give away only duplicate stickers in exchange with different stickers they don't possess.
			Can you help Bob and tell him the maximum number of different stickers he can get by trading stickers with his friends?
Input   :
			2	//case
			2 5	//people candy kind		max ~10  ~25
			6 1 1 1 1 1 1	//num arr..(master)
			3 1 2 2			//num arr..(friend)
			3 5
			4 1 2 1 1
			3 2 2 2
			5 1 3 4 4 3

Output	:
			Case #1: 1
			Case #2: 3
solve:
		maximun flow
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;

#define MAXN 110
#define INF 9999999
int cap[MAXN][MAXN];
int flow[MAXN][MAXN];
int pa[MAXN];
bool v[MAXN];
int n,m;

int tmp[MAXN];

bool DFS(int cur,int t)
{
	int i;
	v[cur]=true;
	if(cur==t)	return true;
	for(i=1;i<=m+n;++i)
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
	int edge;
	int len;
	int i,j;
	int casenum,cc;
	scanf("%d",&casenum);
	for(cc=1;cc<=casenum;++cc)
	{
		printf("Case #%d: ",cc);

		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		memset(pa,0,sizeof(pa));

		scanf("%d%d",&n,&m);

		//master
		scanf("%d",&edge);
		while(edge--)
		{
			scanf("%d",&len);
			cap[0][len]++;
		}
		for(i=1;i<=m;++i)
			cap[i][m+n]=1;

		//friend
		for(i=1;i<=n-1;++i)
		{
			memset(tmp,0,sizeof(tmp));
			scanf("%d",&edge);
			while(edge--)
			{
				scanf("%d",&len);
				tmp[len]++;
			}
			for(j=1;j<=m;++j)
			{
				if(/*cap[0][j]>0 && */tmp[j]==0)
					cap[j][m+i]=1;

				else if(tmp[j]>1)
					cap[m+i][j]=tmp[j]-1;
			}
		}
		/*for(i=0;i<=n+m;++i)
		{
			for(j=0;j<=m+n;++j)
				printf("%d ",cap[i][j]);
			printf("\n");
		}*/
		printf("%d\n",Ford(0,m+n));
	}
	return 0;
}
