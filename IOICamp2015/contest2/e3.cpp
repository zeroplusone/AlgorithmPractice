#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

typedef long long LL;
LL as[7]={2,325,9375,28178,450775,9780504,1795265022};
const bool PRIME=1,COMPOSITE=0;

LL mul(LL a,LL b,LL n)
{
	LL r=0;	a%=n;	b%=n;
	while(b)
	{
		if(b&1)	r=(a+r>=n? a+r-n:a+r);
		a=(a+a>=n? a+a-n:a+a);
		b>>=1;
	}	
	return r;
}

LL bigmod(LL a,LL d,LL n)
{
	if(d==0)	return 1LL;
	if(d==1)	return a%n;
	return mul(bigmod(mul(a,a,n),d/2,n),d%2?a:1,n);
}

LL gcd(LL a,LL b)
{
	if(b==0)	return a;
	else	return gcd(b,a%b);
}

bool miller_rabin(LL n,LL a)
{
	if(gcd(a,n)==n)	return PRIME;
	if(gcd(a,n)!=1)	return COMPOSITE;
	LL d=n-1,r=0,res;
	while(d%2==0)
	{
		++r;
		d/=2;
	}
	res=bigmod(a,d,n);
	if(res==1 || res==n-1)	return PRIME;
	while(r--)
	{
		res=mul(res,res,n);
		if(res==n-1)	return PRIME;
	}
	return COMPOSITE;
}

bool isprime(LL n)
{
	for(int i=0;i<7;++i)
		if(miller_rabin(n,as[i])==COMPOSITE)
			return COMPOSITE;
	return PRIME;
}
/*
#define MAXN 2147483647
bool isPrime[MAXN];
int pTop;
int numOfPrime[MAXN]

void 
*/
int main()
{
	int T,ans;	
	LL a,b,tmp,i;
	//init();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&a,&b);
		if(a>b)
		{
			tmp=a;
			a=b;
			b=tmp;
		}
		ans=0;
		for(i=a;i<=b;i+=2)
		{
			if(i==2)
			{
				ans+=1;
				i--;
				continue;
			}
			else if(i%2==0)	++i;
			ans+=isprime(i)?1:0;
		}	
		printf("%d\n",ans);	
	}
	return 0;
}
