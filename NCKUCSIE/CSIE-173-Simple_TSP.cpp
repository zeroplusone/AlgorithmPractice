#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAX 16
#define INF 9999999
int dp[1<<MAX][MAX];
int map[MAX][MAX];
bool v[MAX];
int n;

int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int go(int set,int now)
{
	//printf("@%d %d\n",set,now);
	if(set==0)
		return map[0][now];
	if(v[now])
		return dp[set][now];
		//printf("$%d\n",dp[set][now]);
	v[now]=true;	
	for(int i=1;i<n;++i)
	{
		if(set & 1<<i)
		{
			dp[set][now]=min(dp[set][now],go(set-(1<<i),i)+map[i][now]);
			//printf("$%d\n",dp[set][now]);
		}
	}
	return dp[set][now];
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(v,false,sizeof(v));
		for(int i=0;i<(1<<n);++i)
			for(int j=0;j<n;++j)
				dp[i][j]=INF;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				scanf("%d",&map[i][j]);
		printf("%d\n",go((1<<n)-2,0));
	}
	return 0;
}