/******************
Judge   : POJ
Problem : 2289-Jamie's Contact Groups
Course  : Course11
discribe: you suggest that she group the contact list and minimize the size of the largest group
Input   :
			3 2			//n(#list ~1000) m(#group 0~m-1 500)
			John 0 1
			Rose 1
			Mary 1
			5 4
			ACM 1 2 3
			ICPC 0 1
			Asian 0 2 3
			Regional 1 2
			ShangHai 0 2
			0 0
Output  :
			2		//, the size of the largest contact group.
			2
Solve   : maximun flow+binary search
			TLE-Ford-Fulkerson Algorithm
			TLE-Edmonds-Karp Algorithm
		  bipartitie(multi) matching+binary search
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
/*
#define MAXN 2000
#define INF 9999999
int cap[MAXN][MAXN];
int flow[MAXN][MAXN];
int pa[MAXN];
bool v[MAXN];
char in[5000];
int m,n;
*/
//TLE-Ford-Fulkerson Algorithm
/*
bool DFS(int cur,int t)
{
	int i;
	v[cur]=true;
	if(cur==t)	return true;
	for(i=0;i<=n+m+1;++i)
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
}*/

//TLE-Edmonds-Karp Algorithm
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
			for(i=0;i<=n+m+1;++i)
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
	int f,df;
	int i,j;
	for(i=0;i<=n+m+1;++i)
	{
		for(j=0;j<=n+m+1;++j)
		{
			rest[i][j]=cap[i][j];
		}
	}
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
/*
bool canbe(int mid)
{
	int all=m*mid;
	if(all<=n)
		return false;
	else
	{
		int i;
		memset(flow,0,sizeof(flow));
		memset(pa,0,sizeof(pa));
		for(i=1;i<=m;++i)
			cap[n+i][n+m+1]=mid;
		//if(Ford(0,n+m+1)==n)
		//if(EK(0,n+m+1)==n)
			return true;
		else
			return false;
	}
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
	//freopen("i","r",stdin);
	int i,j,g;
	char token[]=" \n\r",*ptr;
	string name;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0 && m==0)	break;
		memset(cap,0,sizeof(cap));
		for(i=1;i<=n;++i)
			cap[0][i]=1;
		i=n;
		getchar();
		while(i--)
		{
			gets(in);
			ptr=strtok(in,token);
			for(ptr=strtok(NULL,token);ptr;ptr=strtok(NULL,token))
			{
				g=0;
				for(j=0;j<strlen(ptr);++j)
					g=g*10+(ptr[j]-'0');
				cap[i+1][n+1+g]=1;
			}
		}
		printf("%d\n",binary_search(1,n));
	}
	return 0;
}
*/
// bipartitie matching
#define MAXN 2000
#define INF 9999999
int adj[MAXN][MAXN];
int ans[MAXN][MAXN];
int cap[MAXN];
char in[5000];
bool vy[MAXN];
int m,n;
int res;
bool DFS(int x)
{
	int i,j;
	for(i=0;i<m;++i)
	{
		if(adj[x][i] && !vy[i])
		{
			vy[i]=true;
			if(cap[i]<res)	//cap restrict
			{
				ans[i][cap[i]]=x;	//save ans
				cap[i]++;
				return true;
			}
			else
			{
				for(j=0;j<cap[i];++j)	//if full ,find another answer
				{
					if(DFS(ans[i][j]))
					{
						ans[i][j]=x;
						return true;
					}
				}
			}
		}
	}
	return false;
}
bool canbe(int mid)
{
	//bipartitie matching
	int i;
	memset(cap,0,sizeof(cap));
	for(i=0;i<n;++i)
	{
		memset(vy,false,sizeof(vy));
		res=mid;
		if(!DFS(i))	return false;	//nedd every loop to be true ->sum=n
	}
	return true;
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
	//freopen("i","r",stdin);
	int i,j,g;
	char token[]=" \n\r",*ptr;
	string name;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0 && m==0)	break;
		memset(adj,0,sizeof(adj));
		i=n;
		getchar();
		while(i--)
		{
			gets(in);
			ptr=strtok(in,token);
			for(ptr=strtok(NULL,token);ptr;ptr=strtok(NULL,token))
			{
				g=0;
				for(j=0;j<strlen(ptr);++j)
					g=g*10+(ptr[j]-'0');
				adj[i][g]=1;
			}
		}
		printf("%d\n",binary_search(0,n));
	}
	return 0;
}
