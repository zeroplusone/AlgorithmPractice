#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> color;
vector<int> visit;
int v,e,turn;
#define MAXN 200
int con[MAXN][MAXN];
int flag;

int dfs(int now)
{
	visit[now]=1;	
	for(int i=0;i<v;++i)
	{
		if(con[now][i]==1)
		{
			if(visit[i]==1)
			{
				if(color[i]==color[now])
				{
					flag=1;					
				}	
			}
			else
			{
				color[i]=!color[now];
				dfs(i);
			}
		}
	}
}

int main()
{	
	while(scanf("%d",&v))
	{		
		if(v==0)
			break;
		scanf("%d",&e);
		
			color.clear();
			visit.clear();
			for(int i=0;i<MAXN;++i)
				for(int j=0;j<MAXN;++j)
					con[i][j]=0;
			
			int a,b;
			for(int i=0;i<e;++i)
			{
				scanf("%d %d",&a,&b);
				con[a][b]=1;
				con[b][a]=1;
				color.push_back(-1);
				visit.push_back(0);
			}
			int now=0;
			turn=0;
			flag=0;
			color[0]=0;
			dfs(now);	
			if(flag)
				printf("NOT BICOLORABLE.\n");
			else
				printf("BICOLORABLE.\n");

	}
	return 0;
}