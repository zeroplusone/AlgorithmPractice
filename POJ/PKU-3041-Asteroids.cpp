/******************
Judge   : poj
Problem : 3041-Asteroids
Course  : Course13
discribe:  N x N grid (1 <= N <= 500). The grid contains K asteroids (1 <= K <= 10,000)
			weapon that can vaporize all the asteroids in any given row or column of the grid with a single shot
			find the minimum number of shots Bessie needs to fire to eliminate all of the asteroids.
Input   :
			3 4	//n k
			1 1	//position
			1 3
			2 2
			3 2
Output  :
			2
Solve   : minimun vertex cover
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
#define MAXN 550

int mx[MAXN],my[MAXN];
bool used[MAXN];
double edge[MAXN][MAXN];	//left right

bool DFS(int now,int ny)
{
	int i,next;
	for(i=0;i<ny;++i)
	{
		if(edge[now][i] && !used[i])
		{
			used[i]=true;
			if(my[i]==-1 || DFS(my[i],ny))
			{
				mx[now]=i;
				my[i]=now;
				return true;
			}
		}
	}
	return false;
}

int bipartite(int nx,int ny)
{
	int i,ans=0;
	for(i=0;i<nx;++i)
		mx[i]=-1;
	for(i=0;i<ny;++i)
		my[i]=-1;

	for(i=0;i<nx;++i)
	{
		memset(used,false,(ny+1)*sizeof(bool));
		if(DFS(i,ny))	++ans;
	}
	return ans;
}

int main()
{
	int n,k;
	int i;
	int x,y;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		memset(edge,0,sizeof(edge));
		for(i=0;i<k;++i)
		{
			scanf("%d%d",&x,&y);
			edge[x][y]=1;
		}

		printf("%d\n",bipartite(n+1,n+1));
	}
	return 0;
}
