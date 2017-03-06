#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX 550 
int r[MAX][MAX];
int p[MAX];
int rank[MAX];

struct edge
{
	int v1,v2;
	int l;
	bool operator<(const edge& p)const
	{
		return l<p.l;
	}
}e[MAX*MAX/2];

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
	int n,t,m,max;
	scanf("%d",&t);
	for(int i=0;i<t;++i)
	{
		m=0;	max=0;
		scanf("%d",&n);
		for(int j=0;j<n;++j)
		{
			makeset(j);
			for(int k=0;k<n;++k)
			{
				scanf("%d",&r[j][k]);
				if(r[j][k]!=0 && j>k)
				{	e[m].v1=j;	e[m].v2=k;	e[m].l=r[j][k];	m++;}
			}
		}
		sort(e,e+m);
		
		for(int j=0;j<m;++j)
		{
			if(findset(e[j].v1)==findset(e[j].v2))
				continue;
			else
			{
				link(findset(e[j].v1),findset(e[j].v2));
				if(e[j].l>max)
					max=e[j].l;
			}
		}
		printf("%d\n",max);
	}
}