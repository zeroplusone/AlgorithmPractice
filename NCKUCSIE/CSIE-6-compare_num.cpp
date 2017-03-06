#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int t,n;
	scanf("%d %d",&t,&n);
	
	for(int i=0;i<t;++i)
	{
		int a[n];
		int b[n];
		
		for(int j=0;j<n;++j)
			scanf("%d",&a[j]);			
		for(int j=0;j<n;++j)
			scanf("%d",&b[j]);
		
		int anow=0;
		int bnow=0;
		int count=0;
		while(anow!=n && bnow!=n)
		{
			if(a[anow]>b[bnow])
			{
				bnow++;
			}
			else if(a[anow]==b[bnow])
			{
				count++;
				anow++;
				bnow++;
				
			}
			else
			{
				anow++;
			}
		}
		printf("%d\n",count);	
		
	}
}