/******************
Judge   : UVA
Problem : 10000 - Longest Paths
Course  : Course10
discribe: computes the length of the longest path that can be constructed in a given graph from a given starting point
Input	:
			2	//n(#node)	(1~100)
			1	//start
			1 2	//p->q
			0 0	//end pair
			5	//n (#node)
			3
			1 2	//len=1
			3 5
			3 1
			2 4
			4 5
			0 0
			5	//n (#node)
			5
			5 1
			5 2
			5 3
			5 4
			4 1
			4 2
			0 0
			0	//end

Output	:
			Case 1: The longest path from 1 has length 1, finishing at 2.

			Case 2: The longest path from 3 has length 4, finishing at 5.

			Case 3: The longest path from 5 has length 2, finishing at 1.

solve:
		single source longest path
[bidirection ,no cycle]
*******************/
#include<bits/stdc++.h>
using namespace std;

#define MAXN 150
int d[MAXN];
struct edge
{
	int s,d;
}e[MAXN*MAXN];

int main()
{
	int n,start;
	int from,to;
	int casenum=1,edgenum=0;
	int i,j;
	int ans,index;
	bool change=false;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		
		scanf("%d",&start);
		edgenum=0;
		while(scanf("%d%d",&from,&to))
		{
			if(from==0 && to ==0)	break;
			e[edgenum].s=from;
			e[edgenum].d=to;
			edgenum++;
			/*e[edgenum].s=to;
			e[edgenum].d=from;
			edgenum++;*/
		}
		
		for(i=0;i<=n;++i)	d[i]=-1;
		//bellman
		d[start]=0;	change=false;
		for(i=0;i<n-1;++i)
		{
			for(j=0;j<edgenum;++j)
			{
				from=e[j].s;	to=e[j].d;
				//printf("%d %d : %d %d\n",from,to,d[from],d[to]);
				if(d[from]!=-1 && d[to]<d[from]+1)
				{
					d[to]=d[from]+1;
					change=true;
				}
			}
			if(!change)	break;
			/*for(j=1;j<=n;++j)
				printf("%d ",d[j]);
			printf("\n");*/
		}
		
		//find result
		ans=-1;	index=-1;
		for(i=1;i<=n;++i)
		{
			if(d[i]>ans)
			{
				ans=d[i];
				index=i;
			}
		}
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",casenum++,start,ans,index);
	}
	return 0;
}