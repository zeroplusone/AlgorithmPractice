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
		maximun flow by Ford-Fulkerson
*******************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

#define MAXN 110
#define INF 9999999
int cap[MAXN][MAXN];
int flow[MAXN][MAXN];
int pa[MAXN];
bool v[MAXN];
int n;

int Edmonds_Karp(int s,int t)
{
	//variable
	int now,next,pre,minf,ret;

	//initial
	queue<int> Q;
	while(!Q.empty())	Q.pop();
	memset(v,false,sizeof(v));
	ret=0;

	while(true)
	{
		memset(v,false,sizeof(v));
		//start
		v[s]=true;
		Q.push(s);
		while(!Q.empty())
		{
			now=Q.front();
			Q.pop();

			for(next=1;next<=n;++next)
			{
				if(v[next])	continue;
				else if(cap[now][next]-flow[now][next]>0)
					pa[next]=now;					
				else if(flow[next][now]>0)
					pa[next]=-now;
				v[next]=true;
				Q.push(next);
			}
		}
		if(!v[t])	break;

		minf=INF;
		for(now=t,pre=pa[t];now!=s;pre=pa[now])
		{
			if(pa[now]>0)
				minf=min(minf,cap[pre][now]-flow[pre][now]);
			else 
				minf=min(minf,-flow[now][pre]);
		}
		ret+=minf;
		printf("%d\n",minf);
		for(now=t,pre=pa[t];pre!=s;pre=pa[now])
		{
			if(pa[now]>0)
				flow[pre][now]+=minf;
			else if(flow[next][now])
				flow[-pre][now]-=minf;
		}
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
		printf("The bandwidth is %d.\n\n",Edmonds_Karp(s,t));
	}
	return 0;
}