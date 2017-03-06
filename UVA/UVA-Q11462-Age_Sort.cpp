#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		int a,last;
		int num[101];
		for(int k=0;k<101;++k)
			num[k]=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a);
			num[a]++;
		}		
		for(int l=100;l>0;--l)
		{	
			if(num[l]!=0)
			{	
				last=l;
				break;
			}
		}
		for(int j=1;j<=last;++j)
		{
			if(num[j]!=0)
			{
				
				for(int m=0;m<num[j];++m)
				{
					if(j==last && m==num[j]-1)
						printf("%d",j);
					else
						printf("%d ",j);
				}	
			}			
		}
		printf("\n");
	}
	return 0;
}