/******************
Judge   : POJ
Problem : 2421-Constructing Roads
Course  : Course8
discribe: there are already some roads between some villages and your job is the build some roads such that all the villages are connect and the length of all the roads built is minimum.
Input   : 
			3	//n city
			0 990 692 //graph
			990 0 179
			692 179 0
			1	//q #connection
			1 2	//1 2 connect
Output  : 
			179 //min dis
Solve   : MST 
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
	int n,q;
	int i,j,now,tmp;
	int pa,pb;
	int ans;
	while(scanf("%d",&n)!=EOF)
	{
	
		now=0;	ans=0;
		
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{	
				scanf("%d",&tmp);
				if(j>i)
				{
					e[now].a=i;
					e[now].b=j;
					e[now].val=tmp;
					now++;
				}
			}
		}
		makeset(n);
		scanf("%d",&q);
		for(i=0;i<q;++i)
		{
			scanf("%d %d",&pa,&pb);
			pa--;	pb--;
			pa=findset(pa);	pb=findset(pb);
			if(pa!=pb)
				uniont(pa,pb);
		}

		sort(e,e+now);
		for(i=0;i<now ;++i)
		{
			pa=findset(e[i].a);	pb=findset(e[i].b);
			if(pa!=pb)
			{
				uniont(pa,pb);
				ans+=e[i].val;	
			}
		}
		printf("%d\n",ans);
			
		
	}
	return 0;
}