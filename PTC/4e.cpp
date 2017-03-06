#include <cstdio>
#include <iostream>
#include <cstring>
#include<string>
#include <algorithm>
using namespace std;

#define MAX 45
//#define INF 100000

int p[MAX];
int n;
int ans;
int sum;

void back(int now)
{
	//printf("%d %d\n",now,sum);
	if(now==n || now==n+1)
	{
		if(ans<sum)
			ans=sum;
		return;
	}
	sum+=p[now];
	back(now+1);
	sum+=p[now];
	back(now+2);
	sum-=2*p[now];
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(int i=0;i<n;++i)
			scanf("%d",&p[i]);
		ans=0;
		sum=0;
		back(0);
		printf("%d\n",ans);
	}
	return 0;
}