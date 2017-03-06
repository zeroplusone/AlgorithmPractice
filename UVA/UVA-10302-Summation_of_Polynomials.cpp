#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	long long int n;
	long long int sum;
	while(scanf("%lld",&n)!=EOF)
	{
		sum=0;
		for(long long int i=1;i<=n;++i)
		{
			sum+=i*i*i;			/*注意算式等號前後型態 i改lld*/
		}
		printf("%lld\n",sum);
	}
	return 0;
}

