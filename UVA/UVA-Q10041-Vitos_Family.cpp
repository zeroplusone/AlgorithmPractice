#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
	int n,t,flag;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&t);
		int a[t];
		for(int j=0;j<t;++j)
			scanf("%d",&a[j]);
		sort(a,a+t);
		flag=0;
		for(int k=1;k<t;++k)
		{
			if((a[k]-a[k-1])>1)
			{
				flag=1;
				break;
			}			
		}
		if(flag==0)
			printf("%d\n",a[t-1]-a[0]+1);
		else
			printf("%d\n",a[t-1]-a[0]);
		
	}
	return 0;
}