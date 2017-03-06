/******************
Judge   : poj
Problem : 1384-Piggy-Bank
Course  : Course12
discribe:  find out this worst case and determine the minimum amount of cash inside the piggy-bank.
Input   :
			3	//case
			10 110	//e(empty weight) f(filled weught) ~10000
			2		//n(#money type)~500
			1 1		//price weight ~50000 `10000
			30 50
			10 110	//e f
			2
			1 1
			50 30
			1 6		//e f
			2
			10 3
			20 4
Output  :
			not possible
			10
			2
Solve   : 0/1 Knapsack
		無限，求最小花費
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

#define MAXC 10100
#define MAXN 510
#define INF 9999999
int w[MAXN],p[MAXN];
int dp[MAXC];	//dp[i][j] x=i,y=j 有幾個
int n,f,cap,nc;

void builddp()
{
		int i,j,k;
		int tmp;
		for(i=0;i<=cap;++i)
			dp[i]=INF;
		dp[0]=0;

		for(i=0;i<nc;++i)	//type
		{
			for(j=w[i];j<=cap;++j)	//x
			{

				dp[j]=min(dp[j],dp[j-w[i]]+p[i]);

			}
		}
}

int main()
{
	int t;
	int i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&f);
		cap=f-n;
		scanf("%d",&nc);
		for(i=0;i<nc;++i)
			scanf("%d%d",&p[i],&w[i]);
		builddp();
		/*for(i=0;i<=s*s;++i)
			printf("%d ",dp[m][i]);
		printf("\n");*/
		if(dp[cap]==INF)	//to find min ,setINF
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[cap]);
	}
	return 0;
}
