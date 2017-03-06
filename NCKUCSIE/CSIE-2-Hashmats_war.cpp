#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	long long int a,b,c;
	while(scanf("%lld %lld",&a,&b)!=EOF)
	{
		c=a-b;
		if(c<0)
			c=(-1)*c;
		printf("%lld\n",c);
	}
	return 0;
}