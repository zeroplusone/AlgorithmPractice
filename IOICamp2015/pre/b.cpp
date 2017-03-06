#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int n;
	int a;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&a);
		if(a>1000)
			printf("1000 %d\n",a-1000);
		else
			printf("0 %d\n",a);			
		
	}
	return 0;
}
