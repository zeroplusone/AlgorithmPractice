/******************
Judge   : uva
Problem : 663 - Sorting Slides(1486)
Course  : Course13
discribe:   The slides all have numbers written on them according to their order in the talk. Since the slides lie on each other and are transparent, one cannot see on which slide each number is written.

Input   :
			4	//n
			6 22 10 20	//xmin xmax ymin ymax  A
			4 18 6 16                          B
			8 20 2 18                          C
			10 24 4 8                          D
			9 15		//number position      1
			19 17                              2
			11 7
			21 11
			2
			0 2 0 2
			0 2 0 2
			1 1
			1 1
			0	//end
Output  :
			Heap 1
			(A,4) (B,1) (C,2) (D,3)

			Heap 2
			none

Solve   : bipartite matching
research:确定匹配，先求出最大的匹配。然后依次删除每一条边，再求其最大匹配，如果最大匹配减小，说明这匹配是确定的
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
#define MAXN 110
struct Slidepoi
{
	int xl,xr,yl,yr;
}slide[MAXN];
int mx[MAXN],my[MAXN],tmpmy[MAXN];
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

bool inside(int x,int y,int j)
{
	if(x<slide[j].xr && x>slide[j].xl && y<slide[j].yr && y>slide[j].yl )
		return true;
	else
		return false;
}
int main()
{
	int n;
	int x,y,maxmatch;
	int i,j,tmp;
	int casenum=1;
	bool ya=false,first=true;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		memset(edge,0,sizeof(edge));

		for(i=0;i<n;++i)
		{
			scanf("%d%d%d%d",&slide[i].xl,&slide[i].xr,&slide[i].yl,&slide[i].yr);
		}
		for(i=0;i<n;++i)
		{
			scanf("%d %d",&x,&y);
			for(j=0;j<n;++j)
			{
				if(inside(x,y,j))
				{
					edge[i][j]=1;
				}

			}
		}


		maxmatch=bipartite(n,n);
		for(i=0;i<n;++i)
			tmpmy[i]=my[i]+1;
		ya=false;	first=true;
		printf("Heap %d\n",casenum++);
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				if(edge[j][i]==1)
				{
					edge[j][i]=0;
					if(bipartite(n,n)<maxmatch)
					{
						if(!first)	printf(" ");
						printf("(%c,%d)",'A'+i,tmpmy[i]);
						first=false;
						ya=true;
					}
					edge[j][i]=1;
				}
			}
		}
			if(ya)
				printf("\n\n");
			else
				printf("none\n\n");

	}
	return 0;
}
