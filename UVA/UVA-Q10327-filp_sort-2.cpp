/******************
Judge   : UVA
Problem : 10327-Flip Sort
Course  : Course1
discribe: give a seqence and count the times we need to swap
Input   : N
          a0 a1 a2.. an-1
Output  : Minimum exchange operations : ans		  
Solve   : bubble sort
Date    : 2014-01-27
*******************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX 1010

int main()
{
	int n,count=0;
	int i,j,tmp;
	int a[MAX];
	while(scanf("%d",&n)!=EOF)
	{
		count=0;
		for(i=0;i<n;++i)
			scanf("%d",&a[i]);

		for(i=n-1;i>0;--i)
		{
			for(j=0;j<i;++j)
			{
				if(a[j]>a[j+1])
				{
					tmp=a[j];
					a[j]=a[j+1];
					a[j+1]=tmp;
					count++;
				}				
			}
		}
		printf("Minimum exchange operations : %d\n",count);
	}
	return 0;
}