/******************
Judge   : PKU
Problem : 3262-Protecting_the_Flowers
Course  : Course1
discribe: sequently tranport N cows return in 2 X Ti time. 
          the waiting cow will eat Di flowers/minute.
		  find the min flowers cost.
Input   : N
          T0 D0
		  T1 D1
		  . 
		  .
		  TN-1 DN-1
Output  : ans		  
Solve   : greedy+sort
          first send bigest d/t
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX 100100
struct cow
{
	int t,d;
	float val;
	bool operator<(const cow& a)const
	{
		return val>a.val;
	}	
}c[MAX];

int main()
{
	int n;
	int i,sum;
	long long int ans;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;	ans=0;
		for(i=0;i<n;++i)
		{
			scanf("%d%d",&c[i].t,&c[i].d);
			c[i].val=(float)c[i].d/(float)c[i].t;
			sum+=c[i].d;
		}
		sort(c,c+n);
		for(i=0;i<n;++i)
		{
			sum-=c[i].d;
			ans+=2*c[i].t*sum;
		}
		printf("%lld\n",ans);
	}
	return 0;
}