#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

long long int bigMod(long long int a,long long int b,long long int c)
{
	if(b==0)
		return 1%c;
	else if(b==1)
		return a%c;
	else
	{
		long long int half=bigMod(a,b/2,c);
		if(b%2==0)
			return (half*half)%c;
		else
			return (half*half)%c*a%c;	
	}
}

int main()
{
	int n;
	long long int a,b,c;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		printf("%lld\n",bigMod(a,b,c));			
		
	}
	return 0;
}
