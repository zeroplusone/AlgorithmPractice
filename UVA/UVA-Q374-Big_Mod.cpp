/******************
Judge   : UVA
Problem : 374 - Big Mod
Course  : Course2
discribe: R=B^P mod M
Input   : B
		  P
		  M
		  
		  B
		  P
		  M
		  ...
Output  : R
		  R
		  R
Solve   : recursive
		(B^P)%M = (B^(P/2)%M) * (B^(P/2)%M) 
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

long long int bigmod(long long int b,long long int p,long long int m)
{
	if(p==0)
		return 1;
	else if(p==1)
		return b%m;
	else
	{
		long long int half=bigmod(b,p/2,m);
		if(p%2==0)
			return (half*half)%m;
		else
			return (half*half*(b%m))%m;
	}
}

int main()
{
	long long int b,p,m;
	while(scanf("%lld%lld%lld",&b,&p,&m)!=EOF)
	{		
		printf("%lld\n",bigmod(b,p,m));
	}
	return 0;
}