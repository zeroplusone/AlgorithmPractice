#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	long int n,zero,five,all;
	int tmp;
	while(scanf("%ld",&n)!=EOF)
	{
		zero=0;
		five=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&tmp);
			if(tmp==5)
				five++;
			else
				zero++;
		}
		all=5*five;
		
		if(zero==0)
			printf("-1\n");
		else if(five/9>0)
		{
			for(long int i=0;i<five/9;++i)
				printf("555555555");
			for(long int i=0;i<zero;++i)
				printf("0");
			printf("\n");
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}
