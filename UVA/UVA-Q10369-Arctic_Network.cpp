/******************
Judge   : UVA
Problem : 10369 - Arctic Network
Course  : Course8
discribe: find the s-1 th MAXN edge in MST
Input   : 
			1	//n case
			2 4	//s(minus) p(#node) 
			0 100 // x y
			0 300
			0 600
			150 750
Output  : 
			212.13 //the s-1 th MAXN edge
Solve   : MST
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAXN 550 
double r[MAXN][2];
int p[MAXN];
int rank[MAXN];

struct edge
{
	int v1,v2;
	double l;
	bool operator<(const edge& p)const
	{
		return l<p.l;
	}
}e[MAXN*MAXN/2];

void makeset(int x)
{
	p[x]=x;
	rank[x]=0;
}

int findset(int x)
{
	if(x!=p[x])
		p[x]=findset(p[x]);
	return p[x];
}

void link(int x,int y)
{
	if(rank[x]>rank[y])
		p[y]=x;
	else
	{
		p[x]=y;
		if(rank[x]==rank[y])
			rank[y]++;
	}	
}

int main()
{
	int s,v,t,m;
	scanf("%d",&t);
	for(int i=0;i<t;++i)
	{
		m=0;	
		scanf("%d %d",&s,&v);
		for(int j=0;j<v;++j)
		{
			makeset(j);
			scanf("%lf %lf",&r[j][0],&r[j][1]);
			for(int k=j-1;k>=0;--k)
			{				
				e[m].v1=j;	e[m].v2=k;	
				e[m].l=sqrt((r[j][0]-r[k][0])*(r[j][0]-r[k][0])+(r[j][1]-r[k][1])*(r[j][1]-r[k][1]));
				m++;
			}
		}
		sort(e,e+m);
		int ce=0;	double ans=0;
		for(int j=0;j<m;++j)
		{
			if(findset(e[j].v1)==findset(e[j].v2))
				continue;
			else
			{
				link(findset(e[j].v1),findset(e[j].v2));
				ans=e[j].l;
				ce++;
			}
			if(ce==v-s)
				break;
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}