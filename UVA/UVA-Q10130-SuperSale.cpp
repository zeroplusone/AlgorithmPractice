/******************
Judge   : UVA
Problem : 10130-SuperSale
Course  : Course12
discribe: We have given list of objects with prices and their weight. We also know, what is the maximum weight that every person can stand. What is the maximal value of objects we can buy at SuperSale?
Input   :
			2		//case
			3		//n (#item~1000)
			72 17	//price~100 weight~30
			44 23
			31 24
			1		//g(#people)~100
			26		//w~30
			6
			64 26
			85 22
			52 4
			99 18
			39 13
			54 9
			4
			23
			20
			20
			26
Output  :
			72
			514
Solve   : 0/1 Knapsack
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
#define MAXN 1500
int w[MAXN];
int p[MAXN];
#define MAXB 32
int dp[MAXN][MAXB];

void builddp(int n)
{

		int i,j;
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;++i)
		{
			for(j=0;j<=MAXB;++j)
			{
				if(j-w[i]>=0)
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+p[i]);
				else
					dp[i][j]=dp[i-1][j];
			}
		}
}

int main()
{
	//freopen("u10130","r",stdin);
	int t;
	int n,g,in;
	int ans;
	int i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			scanf("%d%d",&p[i],&w[i]);
		scanf("%d",&g);

		builddp(n);
		ans=0;
		while(g--)
		{
			scanf("%d",&in);
			ans+=dp[n][in];
		}
		printf("%d\n",ans);

	}
	return 0;
}
