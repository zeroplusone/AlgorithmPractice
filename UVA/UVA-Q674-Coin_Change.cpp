/******************
Judge   : UVA
Problem : 674 - Coin Change
Course  : Course12
discribe: Suppose there are 5 types of coins: 50-cent, 25-cent, 10-cent, 5-cent, and 1-cent. We want to make changes with these coins for a given amount of money.
		  Note that we count that there is one way of making change for zero cent.
Input   :
			11
			26
Output  :
			4
			13
Solve   : coin problem
			硬幣無限，湊的到某價位的有幾種
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

#define MAXN 7500
int dp[MAXN];
int v[5];

void build()
{
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	v[4]=50;	v[3]=25;
	v[2]=10;	v[1]=5;
	v[0]=1;
	int i,j,tmp;
	for(i=0;i<5;++i)
	{
		for(j=1;j<MAXN;++j)
		{
			tmp=j-v[i];
			if(tmp>=0 && dp[tmp]>0)
				dp[j]+=dp[tmp];
		}

	}
}

int main()
{
	//freopen("u674","r",stdin);
	build();
	int n;
	while(scanf("%d",&n)!=EOF)
		printf("%d\n",dp[n]);
	return 0;
}
