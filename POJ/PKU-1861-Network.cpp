/******************
Judge   : POJ
Problem : 1861-Network
Course  : Course8
discribe: MST max length+edge
Input   : 
			4 6		//n(node) m(relation)
			1 2 1	//a b len
			1 3 1
			1 4 2
			2 3 1
			3 4 1
			2 4 1
Output  :          wrong example
			1	//max length
			4	//#edge
			1 2 
			1 3
			2 3
			3 4
Solve   : MST 
*******************/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAXE 2000000
#define MAXN 1100
int h[MAXN],p[MAXN];

struct EDGE
{
	int a,b;
	int val;
	bool operator<(const EDGE& p)const
	{
		return val<p.val;
	}
}e[MAXE],ans[MAXN];

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
	int i,j,now,tmp,num;
	int pa,pb;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
	
		now=0;
		
		while(m--)
		{
			scanf("%d %d %d",&i,&j,&tmp);
			e[now].a=i;
			e[now].b=j;
			e[now].val=tmp;
			now++;
		}
		makeset(n);
		sort(e,e+now);
		num=0;
		for(i=0;i<now ;++i)
		{
			pa=findset(e[i].a);	pb=findset(e[i].b);
			if(pa!=pb)
			{
				uniont(pa,pb);
				ans[num]=e[i];
				num++;				
			}
		}
		printf("%d\n",ans[num-1].val);
		printf("%d\n",num);
		for(i=0;i<num;++i)
			printf("%d %d\n",ans[i].a,ans[i].b);
			
		
	}
	return 0;
}