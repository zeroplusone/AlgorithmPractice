/******************
Judge   : poj
Problem : 1325-Machine Schedule(=uva 1194)
Course  : Course13
discribe:  There are two machines A(n mode) and B(m mode).
			For k jobs given, each of them can be processed in either one of the two machines in particular mode.
			 By changing the sequence of the jobs and assigning each job to a suitable machine, please write a program to minimize the times of restarting machines.
Input   :
			5 5 10	//n(#machine A) m(#machine B)~100 k(#job)~1000
			0 1 1
			1 1 2
			2 1 3
			3 1 4
			4 2 1
			5 2 2
			6 2 3
			7 2 4
			8 3 3
			9 4 3
			0
Output  :
			3	//minimal times of restarting machine.
Solve   : minimun vertex cover = bipartite matching
***notice 0 mode don't need to construct edge
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 110
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
	int n,m,k;
	int job,x,y;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		scanf("%d%d",&m,&k);
		memset(edge,0,sizeof(edge));
		while(k--)
		{
			scanf("%d%d%d",&job,&x,&y);
			if(x!=0 && y!=0)
				edge[x][y]=1;
		}

		printf("%d\n",bipartite(n,m));
	}
	return 0;
}
