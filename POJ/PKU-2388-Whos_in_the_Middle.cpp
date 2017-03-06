/******************
Judge   : UVA
Problem : 10107-What_is_the_Median?
Course  : Course1
discribe: find the median 
Input   : n
		  x0
		  x1
		  x2
		  .
		  .
		  xn-1
Output  : med
Solve   : 
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> a(n,0);
	for(int i=0;i<n;++i)
		scanf("%d",&a[i]);
	int max=0,j;
	for(int i=1;i<n;++i)
	{
		max=i-1;
		for(j=i;j<n;++j)
			if(a[j]<a[max])
				max=j;
		swap(a[i-1],a[max]);
	}
	printf("%d\n",a[(n+1)/2-1]);
	return 0;
}

