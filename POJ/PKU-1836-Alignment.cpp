/******************
Judge   : POJ
Problem : 1836-Alignment
Course  : Course9
discribe: where each soldier can see by looking lengthwise the line at least one of the line's extremity (left or right).
			 determines the minimum number of soldiers which have to get out of line. 
			 longest wavio 
Input   : 
			8									//n
			1.86 1.86 1.30621 2 1.4 1 1.97 2.2	//array
Output  : 
			4			
Solve   : lis

*poj no lower_bound
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;

#define MAXN 10010
int lis2[MAXN],lds2[MAXN];
double ary[MAXN];
double lis[MAXN],lds[MAXN];

int main()
{
	int n;
	int i,j,tmp,ans;
	while(scanf("%d",&n)!=EOF)
	{
		ans=0;

		for(i=0;i<=n;++i)
		{
			lis[i]=1;
			lds[i]=1;
		}
		for(i=0;i<n;++i)
		{
			scanf("%lf",&ary[i]);

			for(j=0;j<i;++j)
			{
				if(ary[i]>ary[j] && lis[j]+1>lis[i])
					lis[i]=lis[j]+1;
			}
			lis2[i]=lis2[i-1]<lis[i]?lis[i]:lis2[i-1];
		}
		for(i=n-1;i>=0;--i)
		{

			for(j=n-1;j>i;--j)
			{
				if(ary[i]>ary[j] && lds[j]+1>lds[i])
					lds[i]=lds[j]+1;
			}
			lds2[i]=lds2[i+1]<lds[i]?lds[i]:lds2[i+1];
		}
		for(i=0;i<n;++i)
		{
			tmp=(lis2[i]+lds2[i]-1)<lis2[i]+lds2[i+1]?lis2[i]+lds2[i+1]:(lis2[i]+lds2[i]-1);
			ans=ans<tmp?tmp:ans;
		}
		
		printf("%d\n",n-ans);
	}
	return 0;
}

