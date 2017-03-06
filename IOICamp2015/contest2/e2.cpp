#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

typedef long long LL;


#define MAXN 1000001
bool isPrime[MAXN];
int pTop;
int numOfPrime[MAXN];

void init()
{
	int i,j;
	pTop=0;
	for(i=2;i<MAXN;++i)	isPrime[i]=true;
	numOfPrime[1]=0;	
	for(i=2;i<MAXN;++i)
	{
		if(isPrime[i])
		{
			//prime[pTop++]=i;
			for(j=i*i;j<MAXN;j+=i)
				isPrime[j]=false;
			numOfPrime[i]=numOfPrime[i-1]+1;
		}
		else
			numOfPrime[i]=numOfPrime[i-1];
	}
}

int main()
{
	int T,ans;	
	LL a,b,tmp,i;
	init();
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
		ans=numOfPrime[(int)b]-numOfPrime[(int)a];

		printf("%d\n",ans);	
	}
	return 0;
}
