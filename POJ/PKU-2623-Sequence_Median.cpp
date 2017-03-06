/*
Sample Input
4
3
6
4
5

Sample Output
4.5

算出中間值  機數:中間  偶數:中間兩數相加除2
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAX 250010
unsigned int num[MAX];

int compare(const void* a,const void* b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%u",&num[i]);
	qsort(num,n,sizeof(unsigned int),compare);
	if(n%2==0)	
		printf("%.1f\n",(((float)num[n/2]+(float)num[n/2-1])/2.0));	
	else	
		printf("%.1f\n",(float)num[n/2]);	
	return 0;
}
