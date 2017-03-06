#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main()
{
	long long int what;
	int n;

	while(scanf("%d",&n)!=EOF)
	{
		what=1;		
		if(n<0)
		{
			if(n%2==0)
				printf("Underflow!\n",n);
			else
				printf("Overflow!\n",n);
		}
		else
		{
			for(int j=1;j<=n;++j)
			{
				what=what*j;
				if(what>6227020800)
				{
					what=6227020801;
					break;
				}
				
			}
				
			if(what>6227020800)
				printf("Overflow!\n",n);
			else if(what<10000)
				printf("Underflow!\n",n);
			else
				printf("%lld\n",what);
		}
	}
	return 0;
}