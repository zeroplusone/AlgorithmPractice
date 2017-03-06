/******************
Judge   : UVA
Problem : UVA-10684 - The jackpot
Course  : Course9
discribe: find the max substring MMS
			
Input   : 
			5	//n
			12 -4 	//array
			-10 4 
			9
			3	//n
			-2 -1 -2
			0	//end
Output  : 
			The maximum winning streak is 13.
			Losing streak.
Solve   : MMS
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAX 10010
int dp[MAX];


int main()
{
	int n,ans,money;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		ans=0;
		for(int i=0;i<=n;++i)
			dp[i]=0;
			
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&money);
			/*if(dp[i-1]+money>money) //muney can delete
				dp[i]=dp[i-1]+money;
			else
				dp[i]=money;*/
			if(dp[i-1]>0)
				dp[i]=dp[i-1]+money;
			else
				dp[i]=money;	
			if(dp[i]>ans)	ans=dp[i];
		}
		if(ans>0)
			printf( "The maximum winning streak is %d.\n",ans);
        else
            printf( "Losing streak.\n" );
			
	}
	return 0;
}
