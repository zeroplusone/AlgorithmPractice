#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int a,b;
	a=3;	b=16;
	printf("%d %% %d = %d\n",a,b,a%b);
	a=16;	b=3;
	printf("%d %% %d = %d\n",a,b,a%b);
	a=-3;	b=16;
	printf("%d %% %d = %d\n",a,b,a%b);
	a=3;	b=-16;
	printf("%d %% %d = %d\n",a,b,a%b);
	a=16;	b=-3;
	printf("%d %% %d = %d\n",a,b,a%b);
	a=-16;	b=3;
	printf("%d %% %d = %d\n",a,b,a%b);
	a=-16;	b=-3;
	printf("%d %% %d = %d\n",a,b,a%b);
}

