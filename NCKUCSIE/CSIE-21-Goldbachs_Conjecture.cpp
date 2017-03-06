#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define MAXN 1000000
bool isprime[MAXN];

void build()
{
	memset(isprime,true,sizeof(isprime));
	isprime[0]=false;
	isprime[1]=false;
	for(int i=2;i<sqrt(MAXN);++i)
	{
		if(isprime[i])
		{
			for(int j=i*i;j<MAXN;j=j+i)
				isprime[j]=false;
		}		
	}
}

int main()
{
	build();
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(int i=2;i<n-1;++i)
		{
			if(isprime[i] && isprime[n-i])
			{
				printf("%d = %d + %d\n",n,i,n-i);
				break;
			}
		}
	}
	return 0;
}
