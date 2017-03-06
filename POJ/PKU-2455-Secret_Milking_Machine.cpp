/******************
Judge   : POJ
Problem : 2455-Secret Milking Machine
Course  : Course11
discribe:He must make a total of T (1 <= T <= 200) trips to the machine during its construction.
		FJ knows he cannot use any trail on the farm more than once and that he should try to use the shortest trails.
Input   :
			7 9 2	//n(#land~200) p(#edge~40000) t(#chose road)
			1 2 2	//s t len
			2 3 5
			3 7 5
			1 4 1
			4 3 1
			4 5 7
			5 7 1
			1 6 3
			6 7 3
Output  :
			5
Solve   : maximun flow +binary search
		(bidirection)
*****************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;

#define MAXN 500
#define INF 99999999
int cap[MAXN][MAXN];
int flow[MAXN][MAXN];
int pa[MAXN];
bool v[MAXN];
int adj[MAXN][MAXN];
int n,p,t;

bool DFS(int cur,int t)
{
	int i;
	v[cur]=true;
	if(cur==t)	return true;
	for(i=0;i<=n+1;++i)
	{
		if(v[i])	continue;
		if(adj[cur][i]-flow[cur][i]>0 || flow[i][cur]>0)
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
		if(adj[pre][i]-flow[pre][i]>0)
			f=min(f,adj[pre][i]-flow[pre][i]);
		else
			f=min(f,flow[i][pre]);
	}
	for(i=t;i!=s;i=pa[i])
	{
		pre=pa[i];
		if(adj[pre][i]-flow[pre][i]>0)
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

bool canbe(int mid)
{

	int i,j;
	memset(flow,0,sizeof(flow));
	memset(pa,0,sizeof(pa));

	for(i=1;i<=n;++i)
	{
		for(j=i;j<=n;++j)
		{
			if(cap[i][j]==0)
			{
				adj[i][j]=0;
				adj[j][i]=0;
			}
			else if(cap[i][j]>mid)
			{
				adj[i][j]=0;
				adj[j][i]=0;
			}
			else
			{
				adj[i][j]=1;
				adj[j][i]=1;
			}
		}
	}
	if(Ford(0,n+1)==t)
		return true;
	else
		return false;


}

int binary_search(int beg,int end)
{
	int mid;
	do
	{
		mid=(beg+end)>>1;
		if(canbe(mid))	end=mid;
		else			beg=mid+1;
	}while(beg<end);
	return end;
}

int main()
{
	int i,j;
	int s,e,len;
	int beg=INF,end=0;
	//freopen("i3","r",stdin);
	while(scanf("%d %d %d",&n,&p,&t)!=EOF)
	{
		memset(cap,0,sizeof(cap));
		i=p;
		while(i--)
		{
			scanf("%d %d %d",&s,&e,&len);

			cap[s][e]+=len;
			cap[e][s]+=len;

			beg=cap[s][e]<beg?cap[s][e]:beg;
			end=cap[s][e]>end?cap[s][e]:end;
		}
		adj[0][1]=t;
		adj[n][n+1]=t;
		printf("%d\n",binary_search(beg,end));
	}
	return 0;
}

