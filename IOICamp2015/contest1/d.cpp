#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

#define MAXN 1000100
#define MAXV 55000
int p[MAXN],s[MAXN],a[MAXN];
int dp[MAXN][MAXV];

int main()
{
	int T;
	int n,v;
	int i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&v);
		for(i=1;i<=n;++i)		
			scanf("%d%d%d",&p[i],&s[i],&a[i]);
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;++i)
		{
			for(j=0;j<=v;++j)
			{
				dp[i][j]=dp[i-1][j];
				if(j>0)
				{
					dp[i][j]=max(dp[i][j],dp[i][j-1]);
				}
				if(j>=p[i]*2 && a[i]>=2)
				{
					dp[i][j]=max(dp[i][j],dp[i-1][j-p[i]*2]+s[i]);
					
				}
			}
		}
		printf("%d\n",dp[n][v]);	
	}
}
