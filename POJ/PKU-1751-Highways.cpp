/******************
Judge   : POJ
Problem : 1751-Highways
Course  : Course8
discribe: find the MST cost minus has been build
Input   : 
			9  //n town
			1 5	//x y 
			0 0 
			3 2
			4 5
			5 1
			0 4
			5 2
			1 2
			5 3
			3  //m has been build
			1 3	//town_a town_b 
			9 7
			1 2
Output  : 
			1 6	//need to build
			3 7
			4 9
			5 7
			8 3
Solve   : MST 
*notice : single input(not use while)
*******************/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAXE 700000
#define MAXN 800
int x[MAXN],y[MAXN];
int h[MAXN],p[MAXN];

struct EDGE
{
	int a,b;
	int val;
	bool operator<(const EDGE& p)const
	{
		return val<p.val;
	}
}e[MAXE];

void makeset(int size)
{
	for(int i=0;i<=size;++i)
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
		p[x]=y;
	else
	{
		p[y]=x;
		if(h[x]==h[y])
			h[x]++;
	}	
	
}

int main()
{
	int n,m;
	int i,j,now;
	int pa,pb;
	int sum;
	scanf("%d",&n);
	
		now=0;	sum=0;
		
		for(i=0;i<n;++i)
		{
			scanf("%d %d",&x[i],&y[i]);
		}
		makeset(n);
		scanf("%d",&m);
		for(i=0;i<m;++i)
		{
			scanf("%d %d",&pa,&pb);
			pa--;	pb--;
			pa=findset(pa);	pb=findset(pb);
			if(pa!=pb)
				uniont(pa,pb);
		}
		//add edge
		for(i=0;i<n;++i)
		{
			for(j=i+1;j<n;++j)
			{
				e[now].a=i;
				e[now].b=j;
				e[now].val=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]);
				now++;
			}
		}
		sort(e,e+now);
		for(i=0;i<now /*&& sum <= n-m*/;++i)
		{
			pa=findset(e[i].a);	pb=findset(e[i].b);
			if(pa!=pb)
			{
				uniont(pa,pb);
				sum++;
				printf("%d %d\n",e[i].a+1,e[i].b+1);	
			}
		}

			
		
	
	return 0;
}