#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAX 110
long int a[MAX];

int main()
{
	int n;
	long int max;
	while(scanf("%d",&n)!=EOF)
	{
		max=0;
		for(int i=0;i<n;++i)
		{
			scanf("%ld",&a[i]);
			if(a[i]>max)
				max=a[i];
		}
		if((max-n)%2==0)
			printf("Bob\n");
		else
			printf("Alice\n");
	}
	return 0;
}