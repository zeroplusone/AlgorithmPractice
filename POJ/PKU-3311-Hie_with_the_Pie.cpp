/******************
Judge   : poj
Problem : 3311 - Hie with the Pie
Course  : Course15
discribe:  he would like to take the shortest route in delivering these goodies and returning to the pizzeria, even if it means passing the same location(s) or the pizzeria more than once on the way
Input   :
		3			//#order
		0 1 10 10	//2-dim road
		1 0 1 2
		10 1 0 10
		10 2 10 0
		0			//end

Output	:
			8
solve:
		floyd+TSP
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 13
#define INF 9999999
int r[MAXN][MAXN];
int dp[1<<MAXN][MAXN];
int n;
	//top down
int DP(int s,int i)
{
		
	if(dp[s][i]!=-1)	return dp[s][i];
	if(s==(1<<i))	return dp[s][i]=r[0][i];
	
	int j,ret;
	
	dp[s][i]=INF;
	for(j=0;j<=n;++j)
	{
		if(j==i)	continue;
		if(s & (1<<j))
		{
			ret=DP(s &~(1<<i),j)+r[j][i];
			if(ret<dp[s][i])	dp[s][i]=ret;
		}
	}
	return dp[s][i];
}

void flyod()
{
	int i,j,k;
	for(k=0;k<=n;++k)
		for(i=0;i<=n;++i)
			for(j=0;j<=n;++j)
				if(r[i][k]+r[k][j]<r[i][j])
					r[i][j]=r[i][k]+r[k][j];

}
int main()
{
	int i,j,k;
	int next;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		
		for(i=0;i<=(1<<(n+2));++i)
			for(j=0;j<=n;++j)
				dp[i][j]=-1;
		
		for(i=0;i<=n;++i)		
			for(j=0;j<=n;++j)
				scanf("%d",&r[i][j]);
		flyod();
		
		dp[1][0]=0;
		for(i=1;i<=n;++i)
			dp[1][i]=r[0][i];
		//bottom up
		/*for(i=1;i<(1<<(n+1));++i)
		{
			for(j=0;j<=n;++j)
			{
				if(dp[i][j]!=-1)
				{
					for(k=0;k<=n;++k)
					{
						next=(1<<k)|i;
					
						if(k!=j && (dp[next][k]==-1 || dp[next][k]>dp[i][j]+r[j][k]))
							dp[next][k]=dp[i][j]+r[j][k];
					}
				}
			}
		}*/
		
		printf("%d\n",DP((1<<(n+1))-1,0)/*dp[(1<<(n+1))-1][0]*/);
	}
	return 0;
}