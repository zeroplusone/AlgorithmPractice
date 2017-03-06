#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;

#define MAXN 200100
int dp[MAXN];
int a[MAXN];
deque<int> deq;

int main()
{
	int T,n,k;
	int i,j,ans,sum;

	scanf("%d",&T);
	while(T--)
	{
		while(!deq.empty())	dep.pop();	
		ans=0;	sum=0;
	
		scanf("%d%d",&n,&k);
		for(i=0;i<n;++i)
			scanf("%d",&a[i]);

		sum=dp[0]=a[0];
		dep.push_back(0);		
		for(i=0;i<k-1;++i)
		{	
			a[n+i]=a[i];			
			dp[i+1]=dp[i]+a[i+1];
			if(sum<dp[i+1])
			{
				dp[i+1]=sum;
				for(j=deq.back()+1;j<=i+1;++j)				
					deq.push_back(j);
				
			}
		}	
		ans=sum;
		for(i=1;i<n;++i)
		{
			if(a[i]>=0)
			{
				
			}	
		}
	}
	return 0;
}
