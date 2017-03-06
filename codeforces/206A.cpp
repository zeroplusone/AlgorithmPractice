#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
	int k,d;
	while(scanf("%d %d",&k,&d)!=EOF)
	{
		if(d==0 && k==1)
			printf("0\n");
		else if(d==0)
			printf("No solution\n");
		else
		{
			for(int i=0;i<k-1;++i)
				printf("9");
			printf("%d\n",d);
		}
	}
	return 0;
}