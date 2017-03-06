/******************
Judge   : POJ
Problem : 2560 - Freckles
Course  : Course8
discribe: find the MST cost
Input   : 
			1  // t (case)

			3	//n (node)
			1.0 1.0	//position
			2.0 2.0
			2.0 4.0
Output  : 
			3.41
Solve   : MST
*******************/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAXE 10100
#define MAXN 110
float x[MAXN],y[MAXN];
int h[MAXN],p[MAXN];

struct EDGE
{
	int a,b;
	double val;
	bool operator<(const EDGE& p)const
	{
		return val<p.val;
	}
}e[MAXE];

void makeset(int size)
{
	for(int i=0;i<size;++i)
	{	
		p[i]=i;
		h[i]=0;
	}
}

int findset(int x)
{
	if(x==p[x])
		return x;
	else
		return p[x]=findset(p[x]);
}

void uniont(int x,int y)
{
	if(h[x]<h[y])
	{
		p[x]=y;
	}
	else
	{
		p[y]=x;
		if(h[x]==h[y])
			h[x]++;
	}	
}

int main()
{
	int t,n;
	int i,j,now;
	float ans;
	int sum;
	int pa,pb;
	while(scanf("%d",&n)!=EOF)
	{	
		now=0;	ans=0;	sum=0;
		
		for(i=0;i<n;++i)
		{
			scanf("%f %f",&x[i],&y[i]);
		}
		makeset(n);
		//add edge
		for(i=0;i<n;++i)
		{
			for(j=i+1;j<n;++j)
			{
				e[now].a=i;
				e[now].b=j;
				e[now].val=sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]));
				now++;
			}
		}
		sort(e,e+now);
		for(i=0;i<now && sum < n;++i)
		{
			pa=findset(e[i].a);
			pb=findset(e[i].b);
			if(pa!=pb)
			{
				uniont(pa,pb);
				ans+=e[i].val;
				sum++;
			}
		}
		printf("%.2f\n",ans);
	}
	return 0;
}