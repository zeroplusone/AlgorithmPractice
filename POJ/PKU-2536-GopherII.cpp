/******************
Judge   : poj
Problem : 2536 - Gopher II
Course  : Course13
discribe:  if a gopher does not reach a hole in s seconds it is vulnerable to being eaten. A hole can save at most one gopher. All the gophers run at the same velocity v. The gopher family needs an escape strategy that minimizes the number of vulnerable gophers.
Input   :
			2 2 5 10	//n(#mouse) m(#hole) s(must less than s second to go hole) v(speed)	~100
			1.0 1.0		//position 1
			2.0 2.0		//      ~n
			100.0 100.0	//        1
			20.0 20.0	//       ~m
Output  :
			1	//dead mouse
Solve   : bipartite matching
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
#define MAXN 110
struct POI
{
	double x,y;
}mouse[MAXN],hole[MAXN];
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
	int m,n,s,v;
	int i,j;
	double dx,dy;
	while(scanf("%d%d%d%d",&n,&m,&s,&v)!=EOF)
	{
		memset(edge,0,sizeof(edge));

		for(i=0;i<n;++i)
			scanf("%lf %lf",&mouse[i].x,&mouse[i].y);
		for(j=0;j<m;++j)
			scanf("%lf %lf",&hole[j].x,&hole[j].y);
		for(i=0;i<n;++i)
		{
			for(j=0;j<m;++j)
			{
				dx=hole[j].x-mouse[i].x;
				dy=hole[j].y-mouse[i].y;
				if(double(v*s)>=sqrt(dx*dx+dy*dy))
					edge[i][j]=1;
			}
		}
		printf("%d\n",n-bipartite(n,m));
	}
	return 0;
}
