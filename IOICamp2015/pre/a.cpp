#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int n;
	long long int a,b;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",a+b);			
		
	}
	return 0;
}
