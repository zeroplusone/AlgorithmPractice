/******************
Judge   : poj
Problem : 2446-Chessboard
Course  : Course13
discribe:   board with size M * N. She wants Bob to use a lot of cards with size 1 * 2 to cover the board.
			some holes on the board
Input   :
			4 3 2	//m n k(#hole)
			2 1	//position
			3 3
Output  :
			YES
Solve   : bipartite matching(each position as x y node)
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
#define MAXN 1600

int mx[MAXN],my[MAXN];
bool used[MAXN];
int edge[MAXN][MAXN];	//left right

bool hole[40][40];

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
	int m,n,k;
	int x,y;
	int i,j;
	bool yes=true;
	while(scanf("%d%d%d",&m,&n,&k)!=EOF)
	{
		memset(edge,0,sizeof(edge));
		memset(hole,false,sizeof(hole));

		for(i=0;i<k;++i)
		{
			scanf("%d%d",&y,&x);
			hole[x-1][y-1]=true;
		}
		if((n*m-k)%2==0)
		{
			for(i=0;i<m;++i)
			{
				for(j=0;j<n;++j)
					if(!hole[i][j])
					{
						if(i-1>=0 && !hole[i-1][j])	edge[i*n+j][(i-1)*n+j]=1;
						if(i+1<m && !hole[i+1][j])	edge[i*n+j][(i+1)*n+j]=1;
						if(j-1>=0 && !hole[i][j-1])	edge[i*n+j][i*n+j-1]=1;
						if(j+1<n && !hole[i][j+1])	edge[i*n+j][i*n+j+1]=1;
					}
			}
			//printf("%d\n",bipartite(m*n,m*n));
			if(bipartite(m*n,m*n)==m*n-k)
				yes=true;
			else
				yes=false;
		}
		else
			yes=false;

		if(yes)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
