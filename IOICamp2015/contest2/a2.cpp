#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAXM 10010
int p[MAXM];

long long int nei(long long int n,int m)
{
	long long int re,ans=0;
	
	for(int i=0;i<m-1;++i)
	{
		re=p[i+1]-p[i];
		if(re>2)
		{
			ans+=(re-2)/2+1;
		}
	}
	return ans;
}

int main()
{
	int T;
	long long int n,m;
	int i,tm;
	long long int ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		tm=(int)m;
		p[0]=-1;
		p[tm+1]=n+2;
		for(i=1;i<=tm;++i)
			scanf("%d",&p[i]);
		tm+=2;		
		sort(p,p+tm);
		printf("%lld\n",nei(n,tm));	
	}
	return 0;
}
