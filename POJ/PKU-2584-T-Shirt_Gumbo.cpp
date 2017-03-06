/******************
Judge   : POJ
Problem : 2584-T-Shirt Gumbo
Course  : Course11
discribe:hand out T-shirts to all the contestants in a way that makes everyone happy.
		size  S M L X T
Input   :
			START 1		//n(#people~20)
			ST			//n th people can dress in which size to which size
			0 0 1 0 0	//there are low many shirt
			END			//over
			START 2
			SS TT
			0 0 1 0 0
			END
			START 4
			SM ML LX XT
			0 1 1 1 0
			END
			ENDOFINPUT	//end of all
Output  :
			T-shirts rock!							//yes
			I'd rather not wear a shirt anyway...	//no
			I'd rather not wear a shirt anyway...
Solve   : maximun flow
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<map>
using namespace std;

#define MAXN 50
#define SIZENUM 5
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
	for(i=0;i<=n+SIZENUM+1;++i)
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
	//printf("!!!%d\n",ret);
	return ret;
}

int main()
{
	freopen("i4","r",stdin);
	int i,j;
	string in;
	map<char,int> cloth;
	cloth['S']=1;	cloth['M']=2;	cloth['L']=3;
	cloth['X']=4;	cloth['T']=5;
	while(cin>>in)
	{

		if(in=="ENDOFINPUT")	break;
		scanf("%d",&n);
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		memset(pa,0,sizeof(pa));
		for(i=1;i<=n;++i)
		{
			cap[0][i]=1;
			cin>>in;
			for(j=cloth[in[0]];j<=cloth[in[1]];++j)
			{
				cap[i][j]=1;
				//cap[j][i]=1;
			}
		}
		for(i=1;i<=SIZENUM;++i)
			scanf("%d",&cap[n+i][n+SIZENUM+1]);
		cin>>in;

		if(Ford(0,n+SIZENUM+1)==n)
			printf("T-shirts rock!\n");
		else
			printf("I'd rather not wear a shirt anyway...\n");
		for(i=0;i<=n+6;++i)
		{
			for(j=0;j<=n+6;++j)
				printf("%d ",cap[i][j]);
			printf("\n");
		}
		printf("=====\n");
		for(i=0;i<=n+6;++i)
		{
			for(j=0;j<=n+6;++j)
				printf("%d ",flow[i][j]);
			printf("\n");
		}
	}
	return 0;
}
