/******************
Judge   : uva
Problem : 11159-Factors and Multiples
Course  : Course13
discribe:  Factors and Multiples
Input   :
			2	//t(case)
			4 2 3 4 5	//n n numbers
			4 6 7 8 9	//m m numbers
			3 100 200 300
			1 150
Output  :
			Case 1: 3
			Case 2: 0
Solve   : bipartite matching(maximun independent set)  ask remove -> bipartite
//notice  zero
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
int a[MAXN],b[MAXN];

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
	int t,tt;
	int n,m;
	int i,j;
	scanf("%d",&t);
	for(tt=1;tt<=t;++tt)
	{
		memset(edge,0,sizeof(edge));
		scanf("%d",&n);
		for(i=0;i<n;++i)
			scanf("%d",&a[i]);
		scanf("%d",&m);
		for(j=0;j<m;++j)
			scanf("%d",&b[j]);
		for(i=0;i<m;++i)
		{
			for(j=0;j<n;++j)
			{
				if(a[j]==0)
				{
					if(b[i]==0)
						edge[j][i]=1;
				}
				else if(b[i]%a[j]==0)
					edge[j][i]=1;
			}
		}
		printf("Case %d: ",tt);
		printf("%d\n",bipartite(n,m));
	}
	return 0;
}
