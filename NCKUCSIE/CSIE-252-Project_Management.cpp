/******************
Judge   : NOJ
Problem : 252
Course  : Course7
discribe: calculate the time to do the task with constrains
Input   : 
			5 10 20 30 40 50 //n task time
			4	//m constrains
			1 2	//1 -> 2
			1 3
			2 5
			1 5
Output  : 
			80	//10+20+50
Solve   :   dfs
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 110
int n;
int task[MAXN];
bool r[MAXN][MAXN];
int dag[MAXN];
int ans[MAXN];

void DFS(int now)
{
	for(int i=1;i<=n;++i)
	{
		if(r[now][i] && ans[i]<=ans[now]+task[i])
		{
			ans[i]=ans[now]+task[i];
			DFS(i);
		}
	}
}

int main()
{
	int m;
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		memset(r,false,sizeof(r));
		memset(dag,false,sizeof(dag));
		memset(ans,0,sizeof(ans));
		for(i=1;i<=n;++i)
		{
			scanf("%d",&task[i]);
			ans[i]=task[i];
		}
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d",&i,&j);
			r[i][j]=true;
			dag[j]++;
		}
		for(i=1;i<=n;++i)
			if(dag[i]==0)
				DFS(i);
		int time=0;		
		for(i=1;i<=n;++i)
			time=time>ans[i]?time:ans[i];

		printf("%d\n",time);
	}
	return 0;
}