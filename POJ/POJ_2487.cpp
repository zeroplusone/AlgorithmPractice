#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX 1010
int num[MAX];
int party,borrow;
long long int stamp;

int compare(const void* a,const void*b)
{
	return *(int*)a-*(int*)b;
}

int main()
{	
	long long int sum;
	scanf("%d",&party);	
	for(int k=1;k<=party;++k)
	{		
		scanf("%lld %d",&stamp,&borrow);
		sum=0;
		for(int i=0;i<borrow;++i)
			scanf("%d",&num[i]);		
		qsort(num,borrow,sizeof(int),compare);
		int j;
		for(j=0;j<borrow;j++)
		{	
				sum+=num[borrow-1-j];
				if(sum>=stamp)
					break;
		}		
		if(j==borrow)		
			printf("Scenario #%d:\nimpossible\n\n",k);
		else
			printf("Scenario #%d:\n%d\n\n",k,j+1);
		
	}
	return 0;
}