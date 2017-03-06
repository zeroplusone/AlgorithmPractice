#include <cstdio>
#include <iostream>
#include <cstring>
#include<string>
#include <algorithm>
#include<queue>
using namespace std;

#define MAX 200010
int dis[MAX];
int dp[MAX];
int n;
int big;
queue<int> s;

void bfs()
{
	int now;
	big=0;
	while(!s.empty())
		s.pop();
	/*for(int i=1;i<=5;++i)
		s.push(i);*/
	s.push(0);
	while(!s.empty())
	{
		now=s.front();	s.pop();
		
		if(dp[n+1]!=MAX)
			break;
		if(now+dis[now]>big)
		{
			for(int i=now+1;i<=now+dis[now] && i<=n+1;++i)
			{
				if( dp[now]+1<dp[i])
				{	
					/*for(int j=big;j<=i+dis[i];++j)
						dp[j]=dp[i]+1;*/
					dp[i]=dp[now]+1;
					s.push(i);					
				}
			}
			big=now+dis[now];
			
		}
		/*printf("%d %d\n",now,big);
		for(int i=0;i<=n+1;++i)
			printf("%d ",dp[i]);
		printf("\n");*/
	}
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		dis[0]=5;
		for(int i=1;i<=n;++i)
			scanf("%d",&dis[i]);
		//memset(dp,MAX,sizeof(dp));
		for(int i=1;i<=n+1;++i)
			dp[i]=MAX;
		dp[0]=0; 
		/*for(int i=1;i<=5;++i)
			dp[i]=1;*/
		bfs();
		printf("%d\n",dp[n+1]-1);
	}
	return 0;
}