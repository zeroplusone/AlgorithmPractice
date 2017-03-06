/******************
Judge   : POJ
Problem : 1125-Stockbroker Grapevine
Course  : Course10
discribe:  tells you which stockbroker to choose as your starting point for the rumour, 
			as well as the time it will take for the rumour to spread throughout the stockbroker community. 
			if some people may be unreachable ,then print disjoint
Input	:

			3			//#node(1~100)
			2 2 4 3 5	// #pair  who time(1~10min)
			2 1 2 3 6
			2 1 2 2 2
			5			//#node(1~100)
			3 4 4 2 8 5 3
			1 5 8
			4 1 6 4 10 2 7 5 2
			0
			2 2 5 1 5
			0			//ens

Output	:
			3 2
			3 10
SOL:
floyd
[bidirection ]
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAXN 150
#define INF 999999
int d[MAXN][MAXN];

int main()
{
	int n;
	int i,j,k,who,len,ans;
	int maxt,mint;
	bool isDisjoint=false;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		//reset
		for(i=0;i<=n;++i)
		{
			for(j=0;j<=n;++j)
			{
				if(i==j)	d[i][j]=0;
				else		d[i][j]=INF;
			}
		}
		//
		for(i=1;i<=n;++i)
		{
			scanf("%d",&k);
			while(k--)
			{
				scanf("%d %d",&who,&len);
				d[i][who]=len;
			}
		}
		//floyd
		for(k=1;k<=n;++k)
		{
			for(i=1;i<=n;++i)
			{
				for(j=1;j<=n;++j)
				{
					if(d[i][k]+d[k][j]<d[i][j])
						d[i][j]=d[i][k]+d[k][j];
				}
			}
		}
		//find answer
		ans=0;	mint=INF;
		
		isDisjoint=false;

		for(i=1;i<=n;++i)
		{
			maxt=0;
			for(j=1;j<=n;++j)
				if(d[i][j]>maxt)
					maxt=d[i][j];	//if can not reach some node , it will be INF
				
			
			if(maxt<mint)
			{
				mint=maxt;
				ans=i;
			}
		}
		printf("%d %d\n",ans,mint);
	}
	return 0;
}