/******************
Judge   : UVA
Problem : 369-Combinations.cpp
Course  : Course2
discribe: N thing taken M at a time
          C n¨úm
Input   : N M
		  N m
		  .
		  .
		  0 0		  
Output  : N things taken M at a time is 1192052400 exactly.
Solve   : recursive

*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAX 110
long long int dp[MAX][MAX];
long long int c(int a,int b)
{
	if(a>=0 && b>=0 && dp[a][b])
		return dp[a][b];
	else if(a==b)
		dp[a][b]=1;
	else if(a<b)
		dp[a][b]=0;
	else if(a<=1)
		dp[a][b]=1;
	else if(b==1)
		dp[a][b]=a;
	else if(b==0)
		dp[a][b]=1;
	else
	{
		int tmp=b;
		if(b*2>a)
			tmp=a-b;
		dp[a][b]=c(a-1,tmp)+c(a-1,tmp-1);
	}
	return dp[a][b];
}

int main()
{
	int t;
	int n,m,i;
	memset(dp,0,sizeof(dp));
	while(scanf("%d",&t)!=EOF)
	{
		for(i=0;i<t;++i)
		{scanf("%d %d",&n,&m);
	
		//if(n==0 && m==0)
		//	break;
		printf("%lld\n",c(n,m));}
	}
	return 0;
}