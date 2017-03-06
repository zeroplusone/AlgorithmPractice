#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAXM 10010
long long int p[MAXM];

long long int nei(long long int n,int m)
{
	long long int re,ans=0;
	ans+=p[0]>2?(p[0]+1)/2-1:0;
	ans+=n-p[m-1]>=2?(n-p[m-1])/2:0;
	for(int i=0;i<=m-2;++i)
	{
		re=p[i+1]-p[i]-1;
		if(re>2)
		{
			ans+=(re-3)/2+1;
		}
	}
	return ans;
}

int main()
{
	int T;
	long long int n;
	int i,m;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%d",&n,&m);
		for(i=0;i<m;++i)
			scanf("%lld",&p[i]);
		sort(p,p+m);
		printf("%lld\n",nei(n,m));	
	}
	return 0;
}
