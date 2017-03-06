/******************
Judge   : POJ
Problem : POJ-1505-Copying Books
Course  : IOI
discribe:  sum of niceness values of the roads she bicycles on is maximized
			Positive niceness values indicate roads Jill likes; negative values are used for roads she does not like.
			 If more than one segment is maximally nice, choose the one with the longest cycle ride (largest j-i). To break ties in longest maximal segments, choose the segment that begins with the earliest stop (lowest i). For each route r in the input file, print a line in the form:

			The nicest part of route r is between stops i and j


			However, if the maximal sum is not positive, your program should print:


			Route r has no nice parts
			
Input   : 
			3	//b(case)
			3	//s (stop)
			  -1	//val
			   6
			10	//s (stop)
			   4
			  -5
			   4
			  -3
			   4
			   4
			  -4
			   4
			  -5
			4	//s (stop)
			  -2
			  -3
			  -4
Output  : 
			The nicest part of route 1 is between stops 2 and 3
			The nicest part of route 2 is between stops 3 and 9
			Route 3 has no nice parts
Solve   : MMS
*******************/
/*
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAX 20010
int road[MAX];
int sum[MAX];
int l[MAX];


int DP(int k)
{
	int a=sum[k-1]+road[k];
	l[k]=a<0?0:l[k-1]+1;
	return a>0?a:0;
}

int main()
{
	int b,s;
	scanf("%d",&b);
	sum[0]=0;	l[0]=0;
	for(int i=1;i<=b;++i)
	{
		scanf("%d",&s);
		for(int j=1;j<s;++j)
		{
			scanf("%d",&road[j]);
			sum[j]=DP(j);			
			//printf("%d %d %d\n",j,sum[j],l[j]);
		}
		int max=0;
		for(int j=s-1;j>0;--j)
		{
			if(sum[j]>sum[max])
				max=j;
			else if(sum[j]==sum[max])
			{
				if(l[j]>=l[max])
					max=j;									
			}
		}
		//printf("%d\n",max);
		if(max!=0)
			printf("The nicest part of route %d is between stops %d and %d\n",i,max+1-l[max],max+1);
		else
			printf("Route %d has no nice parts\n",i);
	}
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;

#define MAXS 20100
int mss[MAXS];
int pre[MAXS];

int main()
{
	int b,bb,s,i,in,ans;
	scanf("%d",&b);
	for(bb=1;bb<=b;++bb)
	{
		memset(mss,0,sizeof(mss));
		memset(pre,0,sizeof(pre));
		scanf("%d",&s);
		ans=1;
		for(i=2;i<=s;++i)
		{
			scanf("%d",&in);
			mss[i]=in;
			if(mss[i-1]>=0 && i!=2)
			{
				mss[i]+=mss[i-1];
				pre[i]=pre[i-1];
			}
			else
				pre[i]=i-1;	
			if(mss[i]>=0 && mss[ans]<=mss[i])
			{
				if(mss[ans]==mss[i])
				{
					if(i-pre[i] > ans-pre[ans])
						ans=i;
				}
				else
					ans=i;
			}
		}
		
		if(ans!=1)
			printf("The nicest part of route %d is between stops %d and %d\n",bb,pre[ans],ans);
		else
			printf("Route %d has no nice parts\n",bb);
		
	}
	return 0;
}