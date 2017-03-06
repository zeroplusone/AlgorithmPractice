/******************
Judge   : UVA
Problem : 11747 - Heavy Cycle Edges
Course  : Course8
discribe: output the cycle value
Input   : 
			3 3		//n(node) m(relation)
			0 1 1	//a b len
			1 2 2
			2 0 3
			4 5		//n m
			0 1 1
			1 2 2
			2 3 3
			3 1 4
			0 2 0
			3 1		//n m
			0 1 1
			0 0		//end
Output  : 
			3		//max cycle edge
			2 4
			forest	//if no cycle
Solve   : MST (the edge in Kruskal that not to add to ans)
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
int ans[MAXN];

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
	int i,j,now,tmp,num;
	int pa,pb;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0 && m==0)	break;
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
			}
			else
			{
				ans[num]=e[i].val;
				num++;	
			}
		}
		if(num==0)	printf("forest\n");
		for(i=0;i<num;++i)
			printf("%d%c",ans[i],i==num-1?'\n':' ');
			
		
	}
	return 0;
}