/******************
Judge   : POJ
Problem : 3189-Steady Cow Assignment
Course  : Course11
discribe: find an assignment of cows to barns such that no barn's capacity is exceeded and the size of the range
Input   :
			6 4			//n(#cow ~1000) b(#barn ~20)
			1 2 3 4		//favorite rank
			2 3 1 4
			4 2 3 1
			3 1 2 4
			1 3 4 2
			1 4 2 3
			2 1 3 2
Output  :
			2		//the size of the minumum range of barn rankings
Solve   : maximun flow +binary search
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;

#define MAXN 2005
#define INF 9999999
int cap[MAXN][MAXN];
int flow[MAXN][MAXN];
int pa[MAXN];
bool v[MAXN];
int rank[MAXN][25];
int b,n;

//TLE
/*

bool DFS(int cur,int t)
{
	int i;
	v[cur]=true;
	if(cur==t)	return true;
	for(i=0;i<=n+b+1;++i)
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
*/

/*
int fsum[MAXN];
int rest[MAXN][MAXN];
int BFS(int s,int t)
{
		memset(v,false,sizeof(v));
		queue<int> Q;
		v[s]=true;
		pa[s]=s;
		fsum[s]=INF;
		Q.push(s);


		int now,i;
		while(!Q.empty())
		{
			now=Q.front();	Q.pop();
			for(i=0;i<=n+b+1;++i)
			{
				if(!v[i] && rest[now][i]>0)
				{
					v[i]=true;
					pa[i]=now;
					fsum[i]=min(fsum[now],rest[now][i]);
					Q.push(i);
					if(i==t)	return fsum[t];
				}
			}
		}
	return 0;
}

int EK(int s,int t)
{
	for(i=0;i<=n+b+1;++i)
	{
		for(j=0;j<=n+b+1;++j)
		{
			rest[i][j]=cap[i][j];
		}
	}
	int f,df;
	int i,j;
	for(i=0;i<=n+b+1;++i)
		fsum[i]=INF;
	for(f=0;df=BFS(s,t);f+=df)
	{
		for(i=pa[t],j=t;i!=j;i=pa[j=i])
		{
			flow[i][j]+=df;
			flow[j][i]=(-1)*flow[i][j];
			rest[i][j]=cap[i][j]-flow[i][j];
			rest[j][i]=cap[j][i]-flow[j][i];
		}

	}
	return f;
}
*/
int rest[MAXN][MAXN];
int h[MAXN];
int gap[MAXN];
int DFS2(int i,int df,int s,int t)
{
	if(i==t)	return df;
	int j,f;
	for(j=1;j<=n+b+1;++j)
	{
		if(rest[i][j]>0 && h[i]=h[j]+1)
		{
			f=DFS2(j,min(df,rest[i][j],s,t));
			if(f)
			{
				rest[i][j]-=f;
				rest[i][j]+=f;
				return f;
			}
		}
	}
	if(--gap[h[i]==0)
}
int ISAP(int s,int t)
{
	for(i=0;i<=n+b+1;++i)
	{
		for(j=0;j<=n+b+1;++j)
		{
			rest[i][j]=cap[i][j];
		}
		h[i]=0;
	}
	int f=0;
	while(h[s]<=n+b+1)
		f+=DFS2(s,INF,s,t);
	return f;
}
bool canbe(int mid)
{

	int i,j,k;
	for(k=1;k<=b-mid+1;++k)
	{
		memset(flow,0,sizeof(flow));
		memset(pa,0,sizeof(pa));
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=b;++j)
			{
				if(j>=k && j<=k+mid-1)
					cap[i][n+rank[i][j]]=1;
				else
					cap[i][n+rank[i][j]]=0;
			}
		}
		//if(Ford(0,n+b+1)==n)
		if(ISAP(0,n+b+1)==n)
		//if(EK(0,n+b+1)==n)
			return true;
		else
			continue;
	}
	return false;
}

int binary_search(int beg,int end)
{
	int mid;
	while(beg<end)
	{
		mid=(beg+end)>>1;
		if(canbe(mid))	end=mid;
		else			beg=mid+1;
	}
	return end;
}

int main()
{
	int i,j;
	//freopen("i2","r",stdin);
	while(scanf("%d %d",&n,&b)!=EOF)
	{
		memset(cap,0,sizeof(cap));
		for(i=1;i<=n;++i)
			cap[0][i]=1;

		for(i=1;i<=n;++i)
			for(j=1;j<=b;++j)
				scanf("%d",&rank[i][j]);
		for(j=1;j<=b;++j)
				scanf("%d",&cap[n+j][n+b+1]);
		printf("%d\n",binary_search(1,b));
	}
	return 0;
}

