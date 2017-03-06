#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAXM 10010
int p[MANM];

long long int nei(long long int n,int m)
{
	long long int re=0;
	if(p[0]==1)	re++;
	if(p[m]==n)	re++;
	
	for(int i=0;i<m-1;++i)
	{
		if(p[i+1]-p[i]==1)
	}
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
		for(i=0;i<tm;++i)
			scanf("%d",&p[i]);
		sort(p,p+tm);
		ans=n-m-2*m+nei(n,tm);
		printf("%lld\n",ans);	
	}
	return 0;
}
