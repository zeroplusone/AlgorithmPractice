/******************
Judge   : uva
Problem : 10092 - The Problem with the Problem Setter
Course  : Course13
discribe: set problem to its categories
Input   :
			as many as 100 analytical problems from as many as 20 categories.
			3 15		//n(#ca) m(#problem)
			3 3 4		//ca capcity
			2 1 2		//1st problem can be send to which cat
			1 3
			1 3
			1 3
			1 3
			3 1 2 3
			2 2 3
			2 1 3
			1 2
			1 2
			2 1 2
			2 1 3
			2 1 2
			1 1
			3 1 2 3
			3 15	//n m
			7 3 4
			2 1 2
			1 1
			1 2
			1 2
			1 3
			3 1 2 3
			2 2 3
			2 2 3
			1 2
			1 2
			2 2 3
			2 2 3
			2 1 2
			1 1
			3 1 2 3
			0 0		//end
Output  :
			1	//can
			8 11 12	//problecms in cat 1
			1 6 7
			2 3 4 5
			0	//cannot
Solve   : bipartite matching
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
#define MAXN 1100
int cap[30];
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
	int m,n,tmp,in,all;
	int i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0 && m==0)	break;
		memset(edge,0,sizeof(edge));

		cap[0]=0;
		all=0;
		for(i=1;i<=n;++i)
		{
			scanf("%d",&tmp);
			all+=tmp;
			cap[i]=cap[i-1]+tmp;
		}

		for(i=1;i<=m;++i)
		{
			scanf("%d",&tmp);
			while(tmp--)
			{
				scanf("%d",&in);
				for(j=cap[in-1];j<cap[in];++j)
					edge[j][i]=1;
			}

		}
		if(bipartite(all+1,m+1)==all)
		{
			printf("1\n");
			for(i=1;i<=n;++i)
			{
				for(j=cap[i]-1;j>=cap[i-1];--j)
				{
					printf("%d%c",mx[j],j==cap[i-1]?'\n':' ');
				}
			}
		}
		else
			printf("0\n");
	}
	return 0;
}
