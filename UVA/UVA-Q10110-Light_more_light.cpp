#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	unsigned int n;
	int sqr;
	while(scanf("%d",&n)!=EOF)
	{
		if(!n)
			break;
		sqr=(int)sqrt(n);
		if(sqr*sqr==n)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}