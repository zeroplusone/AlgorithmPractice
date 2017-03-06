#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX 110
int a[MAX];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		sort(a,a+n);
		printf("%d ",a[n-1]);
		for(int i=1;i<n-1;++i)
			printf("%d ",a[i]);
		printf("%d\n",a[0]);
	}
	return 0;
}