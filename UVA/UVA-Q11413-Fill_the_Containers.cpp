#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

#define MAX 1010
long long int milk[MAX];
int n,m;

bool canbe(int num)
{
	long long int sum=0;
	int c=0;
	for(int i=0;i<n;++i)
	{
		if(sum<=num)
			sum+=milk[i];
		else
		{
			sum=0;
			c++;
		}
	}
	if(c<=m)
		return true;
	else
		return false;
}

int main()
{
	
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;++i) 
			scanf("%lld",&milk[i]);
			
		long long int left=0,right=0;
		for(int i=0;i<n;++i)
		{
			right+=milk[i];
			if(milk[i]>left)	
				left=milk[i];
		}
		
		int mid;
		
		do
		{
			mid=(left+right)/2;
			if(canbe(mid))
				right=mid;
			else
				left=mid+1;
		}while(left<right);
	}
	return 0;
}