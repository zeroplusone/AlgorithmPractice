/******************
Judge   : UVA
Problem : UVA-Q558-Wormholes.cpp
Course  : Course9
discribe:  return to the starting field a time before his initial departure.
Input   : 
			2		//f(case)
			3 3 	//n(#node) m(positve)
			0 1 1000
			1 2 15
			2 1 -42
			4 4		//n(#node) m(positve)
			0 1 10
			1 2 20
			2 3 30
			3 0 -60

Output  : 
			NO
			YES
Solve   : 1.loop every node as start , shortest path (nagatuve cycle) by bellman-ford

		  2. if there are negative
[bidirection negative]
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n,m;
#define MAX 2010
#define INF 1000000000
int x[MAX],y[MAX],t[MAX];
int d[MAX];

bool Bellman_Ford(int start)
{
	for(int i=0;i<n;++i)
		d[i]=INF;
	d[start]=0;
	
	int e1,e2;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			e1=x[j];
			e2=y[j];
			if(d[e1]+t[j] < d[e2])
				d[e2]=d[e1]+t[j];
		}
	}
	
	for(int j=0;j<m;++j)
	{
		e1=x[j];
		e2=y[j];
		if(d[e1]+t[j] < d[e2])
			return false;
	}
	return true;
}

int main()
{
	
	int c;
	scanf("%d",&c);
	for(int i=0;i<c;++i)
	{
		scanf("%d %d",&n,&m);
		for(int j=0;j<m;++j)
			scanf("%d %d %d",&x[j],&y[j],&t[j]);
		if(!Bellman_Ford(0))
			printf("possible\n");
		else
			printf("not possible\n");
		
	}
	return 0;
}