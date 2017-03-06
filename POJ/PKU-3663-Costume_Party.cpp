/******************
Judge   : PKU
Problem : 3663-Costume Party
Course  : Course1
discribe: count how many pairs that sum is less than S
Input   : N S
          a0
		  a1
		  .
		  .
		  an-1
Output  : ans		  
Solve   : sort
          i from start,j from end
		  if the sum is less than s ans+=j-i
		  (every from i+1 to j can be count) 
		  else find small j
*******************/
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 20100
int a[MAX];

int main()
{
	int n,s;
	int i,j;
	int ans;
	while(scanf("%d %d",&n,&s)!=EOF)
	{
		ans=0;
		for(i=0;i<n;++i)
			scanf("%d",&a[i]);
		sort(a,a+n);
		for(i=0,j=n-1;i<j;)
		{
			if(a[i]+a[j]<=s)
			{
				ans+=j-i;
				i++;
			}
			else			
				j--;			
		}
		printf("%d\n",ans);
	}
	return 0;
}