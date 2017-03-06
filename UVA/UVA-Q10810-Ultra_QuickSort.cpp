/******************
Judge   : UVA
Problem : 10810-Ultra_QuickSort
Course  : Course1
discribe: give a seqence and count the times we need to swap
Input   : N
          a0 a1 a2.. an-1
		  END n=0
Output  : ans		  
Solve   : merge sort
!!!!! count+=mid+1-i;
*******************/
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
using namespace std;
long long int count;    //POJ­nlong long
int a[500000];
int b[500000];
int n;	

void mergesort(int a[],int low,int high)
{	
	if(low<high)
	{		
		mergesort(a,low,(low+high)/2);
		mergesort(a,(low+high)/2+1,high);
		//merge
			/*b.resize(0);	
			int mid=(low+high)/2;	
			int i,j;
			for(i=0,j=mid+1;i<=mid || j<=high;)
			{
				if(i>mid)
				{
					b.push_back(a[j++]);
					++count;
				}
				else if(j>high)
				{
					b.push_back(a[i++]);
				}
				else if(a[i]>a[j])
				{
					b.push_back(a[j++]);
					++count;
				}
				else
				{
					b.push_back(a[i++]);					
				}				
			}
			int l,k;
			for(k=low,l=0;k<=high;++k,++l)
				a[k]=b[l];*/
		//end merge
		//------------------
			int mid=(low+high)/2;	
			int i,j;
			int k=-1;
			for(i=low,j=mid+1;i<=mid || j<=high;)
			{
				if(i>mid)
				{
					b[++k]=a[j++];
				}
				else if(j>high)
				{
					b[++k]=a[i++];
				}
				else if(a[i]>=a[j])
				{					
					b[++k]=a[j++];	
					//count+=j-(low+k)-1;
					count+=mid+1-i;
				}
				else
				{					
					b[++k]=a[i++];						
				}				
			}
			
			for(i=low,j=0;i<=high;++i,++j)
			{				
				a[i]=b[j];				
			}
			
	}	
}

int main()
{
	
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)		
			break;
		count=0;
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);					
		mergesort(a,0,n-1);
		printf("%lld\n",count);
	}
	return 0;

}
