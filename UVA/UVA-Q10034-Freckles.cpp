/******************
Judge   : UVA
Problem : 10034 - Freckles
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
/*
#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAX 130
double f[MAX][2];
bool v[MAX];
double d[MAX];
double l[MAX][MAX],ans;
int e;

void table()
{
	double len;
	for(int i=0;i<e-1;++i)	
		for(int j=i+1;j<e;++j)		
			l[i][j]=l[j][i]=sqrt((f[j][0]-f[i][0])*(f[j][0]-f[i][0])+(f[j][1]-f[i][1])*(f[j][1]-f[i][1]));
}

void print()
{
	for(int i=0;i<e;++i)	
	{
		for(int j=0;j<e;++j)	
			printf("%2lf ",l[i][j]);
		printf("\n");
	}
}

void find()
{

	d[0]=0;
	for(int i=0;i<e;++i)
	{
		int a=-1;		double min=100000;
		for(int j=0;j<e;++j)
		{
			if(!v[j] && d[j]<min)
			{				
				a=j;
				min=d[j];
			}			
		}
		ans+=min; 
		if(a==-1)	break;
		v[a]=true;
		
		for(int j=0;j<e;++j)
		{
			if(!v[j] && l[a][j] < d[j])
			{
				d[j]=l[a][j];
					
			}
		}
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	bool first=true;
	while(scanf("%d",&e)!=EOF)
	{
		if(first)	first=false;
		else	printf("\n");
		
		for(int i=0;i<e;++i)
			scanf("%lf %lf",&f[i][0],&f[i][1]);
			
		memset(l,0,sizeof(l));	memset(v,false,sizeof(v));
		for(int i=0;i<e;++i)	d[i]=100001;
		
		table();
		ans=0;
		find();
		printf("%.2lf\n",ans);
	}
	return 0;
}
*/
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
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		
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
		if(t)	printf("\n");
	}
	return 0;
}