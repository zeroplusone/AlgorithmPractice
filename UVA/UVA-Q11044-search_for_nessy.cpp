#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int n;
	int i;
	int a,b;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;++i)
		{	
			scanf("%d %d",&a,&b);
			a=(a-2)%3==0?(a-2)/3:(a-2)/3+1;
			b=(b-2)%3==0?(b-2)/3:(b-2)/3+1;
			printf("%d\n",a*b);
		}
	}
	return 0;
}