//http://www.algorithmist.com/index.php/UVa_11597

#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;

int main()
{
	int n,c=1;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		printf("Case %d: %d\n",c,n/2);
		c++;
	}
	return 0;
}