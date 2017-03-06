/*
Sample Input

2 1 1 2 (0,1)20 (1,0)10 (0)15 (1)20   //2個NODE 1個POWER(起點) 1個CONSUME(終點) 2條邊
										邊的資料  POWER CONSUME       
										
7 2 3 13 (0,0)1 (0,1)2 (0,2)5 (1,0)1 (1,2)8 (2,3)1 (2,4)7
         (3,5)2 (3,6)5 (4,2)7 (4,3)5 (4,5)1 (6,0)5
         (0)5 (1)2 (3)2 (4)1 (5)4
Sample Output

15
6

求最大CONSUME量
SOL->MAXIMUN FLOW
	新建一個起點連到所有POWER 終點一樣
	POWER CONSUME有限定直 拆成兩個點
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

#define MAX 300
#define INF 1000000
int flow[MAX][MAX];
int cap[MAX][MAX];
bool v[MAX];
int p[MAX],c[MAX];
int path[MAX];
int all;
queue<int> que;

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

int FordFulkerson(int s,int t)
{
	int ans=0;
	int add;
	while(1)
	{
		
		if(!BFS(s,t))
			break;
		add=findflow(s,t);	
		ans+=add;	
	}
	return ans;
}

int main()
{
	int n,np,nc,nt,m;
	int start,end;
	int v1,v2,c;
	int i;
	char ch,tmp1,tmp2;
	while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF)
	{
		memset(flow,0,sizeof(flow));
		memset(cap,0,sizeof(cap));
		for(i=0;i<m;++i)
		{
			do{
				ch=getchar();
			}while(ch!='(');
			scanf("%d%c%d%c%d",&v1,&tmp1,&v2,&tmp2,&c);
			cap[v1][v2]=c;
		}
		start=n+np+nc;	end=n+np+nc+1;
		all=end+1;
		for(i=n;i<n+np;++i)
		{
			do{
				ch=getchar();
			}while(ch!='(');
			scanf("%d%c%d",&v1,&tmp1,&c);
			cap[start][i]=INF;
			cap[i][v1]=c;
		}
		for(i=n+np;i<n+np+nc;++i)
		{
			do{
				ch=getchar();
			}while(ch!='(');
			scanf("%d%c%d",&v1,&tmp1,&c);
			cap[v1][i]=c;
			cap[i][end]=INF;
		}
		printf("%d\n",FordFulkerson(start,end));
	}
	return 0;
}