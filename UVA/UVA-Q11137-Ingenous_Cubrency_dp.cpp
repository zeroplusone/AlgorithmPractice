#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 10005
#define MAXC 21
int val[MAXC];
long int dp[MAX];

int main()
{
	int n;
	int i,j;
		
	for(i=1;i<=21;++i)
		val[i-1]=i*i*i;
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<21;++i)
		{
			for(j=val[i];j<=n;++j)
			{
				dp[j]+=dp[j-val[i]];
				printf("%d %d %d %d\n",j,dp[j],dp[j-val[i]],j-val[i]);
			}
		}
		printf("%ld\n",dp[n]);
	}
	return 0;
}