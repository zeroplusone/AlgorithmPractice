#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		int a[n];
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		sort(a,a+n);
		for(int i=0;i<n;++i)
		{
			if(i==n-1)
				printf("%d\n",a[i]);
			else
				printf("%d ",a[i]);
			
		}
	}
	return 0;
}