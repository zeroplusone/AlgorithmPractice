#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAX 55
int c[MAX];
int dp[MAX][MAX];

int stick(int a,int b)
{
	if(dp[a][b]!=-1)
		return dp[a][b];
	else if(b-a==1)
	{
		dp[a][b]=0;
		return dp[a][b];
	}
	else if(b-a==2)
	{
		dp[a][b]=c[b]-c[a];
		return dp[a][b];
	}
	int min=999999,tmp;
	for(int i=a+1;i<b;++i)
	{
		tmp=stick(a,i)+stick(i,b);
		if(tmp<min)
			min=tmp;
	}
	dp[a][b]=c[b]-c[a]+min;
	return dp[a][b];
}

int main()
{
	int l,n,ans;
	while(scanf("%d",&l)!=EOF)
	{
		if(l==0)
			break;
		memset(dp,-1,sizeof(dp));
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",&c[i]);
		c[0]=0;	c[n+1]=l;	
		printf("The minimum cutting is %d.\n",stick(0,n+1));
	}
	return 0;
}