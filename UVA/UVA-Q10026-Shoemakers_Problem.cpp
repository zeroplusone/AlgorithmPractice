/******************
Judge   : UVA
Problem : 10026-Shoemakers_Problem
Course  : Course1
discribe: find the order of t tasks that min fine
         (fine per day delay)
Input   : n(case)
		  (
			t
			t0 f0
			t1 f1
			.
			.
			tn-1 fn-1
		  )Xn
Output  : order 1~n
Solve   : sort by f/t
*******************/
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

typedef struct num num;
struct num
{
	int time;
	int fine;
	float val;
}; 

int main()
{
	int n,t,l;
	scanf("%d",&n);
	
	for(int i=0;i<n;++i)
	{
		scanf("\n\n%d",&t);
		
			num a[t];
			int sort[t];
			for(int o=0;o<t;++o)
				sort[o]=0;
			for(int j=0;j<t;++j)
			{
				scanf("%d %d",&a[j].time,&a[j].fine);
				a[j].val=(float)(a[j].fine)/(float)(a[j].time);	
		
			}
			
			for(int k=0;k<t;++k)
			{			
				for(l=k-1;l>=0;--l)
				{
					if(a[sort[l]].val>=a[k].val)
					{
						sort[l+1]=sort[l];
					}
					else 
						break;
				}
				sort[l+1]=k;	
				
			}
			for(int m=t-1;m>=0;--m)
			{
			
				if(m==0)
					printf("%d",sort[m]+1);
				else
					printf("%d ",sort[m]+1);
			}
			printf("\n");
			if(i!=n-1)
				printf("\n");

		
	}	
	return 0;
}