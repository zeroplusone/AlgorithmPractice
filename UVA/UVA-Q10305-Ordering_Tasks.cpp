/******************
Judge   : UVA
Problem : 10305 - Ordering Tasks
Course  : Course7
discribe:  give you a graph and then output topological sort
Input   : 	5 4		//n(node) m(#edge) 
			1 2		//i->j
			2 3
			1 3
			1 5
			===========
			0 0   //end
			
Output  : 	1 4 2 5 3
Solve   :	topological sort
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;

#define MAXN 110
bool r[MAXN][MAXN];
bool visited[MAXN]; 
int dag[MAXN];
int n;
int ansnow;
int ans[MAXN];

void DFS(int now)
{
	visited[now]=true;
	for(int i=1;i<=n;++i)
	{
		if(r[now][i] && !visited[i])
		{
			DFS(i);
		}			
	}
	ans[ansnow]=now;
	ansnow--;
	
}

int main()
{
	int m;
	int i,j;
	int s;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0 && m==0)	break;
		memset(r,false,sizeof(r));
		memset(dag,0,sizeof(dag));
		memset(visited,false,sizeof(visited));
		memset(ans,0,sizeof(ans));
		s=-1;
		while(m--)
		{
			scanf("%d %d",&i,&j);
			r[i][j]=true;
			dag[j]++;
		}
		ansnow=n-1;
		for(i=1;i<=n;++i)		
			if(dag[i]==0)				
				DFS(i);
			
		for(i=0;i<n;++i)
			printf("%d%c",ans[i],i==n-1?'\n':' ');
		
	}
	return 0;
}
