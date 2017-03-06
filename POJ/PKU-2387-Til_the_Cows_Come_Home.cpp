/******************
Judge   : POJ
Problem : 2387-Til the Cows Come Home
Course  : Course9
discribe: n to 1 min distance
Input   : 
			5 5	// #edge #v
			1 2 20	//v1 v2 dis
			2 3 30
			3 4 20
			4 5 20
			1 5 100
Output  : 
			90
Solve   : shortest path	by bellman-ford
[bidirection positve]
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAXN 2200
#define INF 999999
int r[MAXN];

struct EDGE
{
	int a,b,len;
}e[MAXN*2];

int main()
{
	int n,t;
	int i,j,now;
	int x,y,l;
	while(scanf("%d %d",&t,&n)!=EOF)
	{
		now=0;
		for(i=0;i<n;++i)		
			r[i]=INF;
		r[n-1]=0;
		for(i=0;i<t;++i)
		{
			scanf("%d %d %d",&x,&y,&l);
			x--;	y--;
			e[now].a=x;	e[now].b=y;	e[now].len=l;	now++;
			e[now].a=y;	e[now].b=x;	e[now].len=l;	now++;
		}
		for(i=0;i<n-1;++i)	//bellman-ford
		{
			for(j=0;j<now;++j)
			{
				x=e[j].a;	y=e[j].b;
				if(r[y]>r[x]+e[j].len)
					r[y]=r[x]+e[j].len;
					
			}
		}
		printf("%d\n",r[0]);
	}
	return 0;
}