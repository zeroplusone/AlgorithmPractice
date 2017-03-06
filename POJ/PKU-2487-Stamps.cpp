/*
Sample Input
3                  //幾筆資料
100 6             //要100張郵票 有6個朋友
13 17 42 9 23 57
99 6
13 17 42 9 23 57
1000 3
314 159 265

Sample Output
Scenario #1:
3                 //最少需要幾個朋友能集夠

Scenario #2:
2

Scenario #3:
impossible
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX 1002
int num[MAX];
int tmp[MAX];
int party,borrow;
long long int stamp;
void mergesort(int l,int r)
{
	if(r-l==1)
		return;
	int mid=(l+r)/2;
	mergesort(l,mid);
	mergesort(mid,r);
	for(int p1=l,p2=mid,p=0;p<r-l;)
	{
		if((num[p1]>num[p2] && p1!=mid) || p2==r)
			tmp[p++]=num[p1++];
		else
			tmp[p++]=num[p2++];		
	}
	
	for(int i=l;i<r;++i)
		{num[i]=tmp[i-l];}
}

int main()
{	
	long long int sum;
	scanf("%d",&party);
	printf("%d",party);
	for(int k=1;k<=party;++k)
	{		
		scanf("%lld %d",&stamp,&borrow);
		sum=0;
		for(int i=0;i<borrow;++i)
			scanf("%d",&num[i]);
		mergesort(0,borrow);
		int j;
		for(j=0;j<borrow;)
		{	
				sum+=num[j++];
				if(sum>=stamp)
					break;
		}
		if(j==borrow)		
			printf("Scenario #%d:\nimpossible",k);
		else
			printf("Scenario #%d:\n%d\n\n",k,j+1);
		
	}
	return 0;
}