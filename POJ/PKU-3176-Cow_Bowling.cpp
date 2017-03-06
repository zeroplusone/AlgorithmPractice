/******************
Judge   : POJ
Problem : 3176-Cow Bowling
Course  : Course9
discribe: bowling balls from its tip and moving "down" to "bottom"
			the sum of the numbers of the cows visited along the way. The cow with the highest score wins that frame. 
			
Input   : 
			5	//n
			7	//bowling number
			3 8
			8 1 0
			2 7 4 4
			4 5 2 6 5
Output  : 
			30
Solve   : dp
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAXN 360
int r[MAXN][MAXN],dp[MAXN][MAXN];

int main()
{
	int n;
	int i,j;
	int ans;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;++i)
		{
			for(j=0;j<i;++j)
			{
				scanf("%d",&r[i][j]);
				dp[i][j]=r[i][j];
			}
		}	
		for(i=1;i<n;++i)
		{
			for(j=0;j<i;++j)
			{	
				dp[i+1][j]=r[i+1][j]+dp[i][j]>dp[i+1][j]?r[i+1][j]+dp[i][j]:dp[i+1][j];
				dp[i+1][j+1]=r[i+1][j+1]+dp[i][j]>dp[i+1][j+1]?r[i+1][j+1]+dp[i][j]:dp[i+1][j+1];
			}
		}	
		/*for(i=1;i<=n;++i)
		{
			for(j=0;j<i;++j)
			{	
				printf("%d ",dp[i][j]);
			}
			printf("\n");
		}*/
		ans=0;
		for(i=0;i<n;++i)
			ans=ans<dp[n][i]?dp[n][i]:ans;
		printf("%d\n",ans);
	}
	return 0;
}