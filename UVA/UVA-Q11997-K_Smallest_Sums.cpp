/******************
Judge   : UVA
Problem : 11997 - K Smallest Sums
Course  : Course6
discribe:  pick exactly one element in each array and calculate the sum of the integers. Your task is to find the k smallest sums among them.
Input   : 	3			//n
			1 8 5		//array1
			9 2 5		//array2
			10 7 6		//array3
			=========
			2
			1 1
			1 2
			
Output  : 	S-Tree #1:
			9 10 12		//1+2+6 1+2+7 1+5+6
			2 2			//1+1 1+1
Solve   :	heap
            layer by layer . only choose smallest k sum
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

#define MAXN 800
int a[MAXN],b[MAXN];

int main()
{
	int n;
	int i,j,k;
	int tmp;
	bool ya=false;
	priority_queue<int> ans;
	while(scanf("%d",&n)!=EOF)
	{
		while(!ans.empty())	ans.pop();
		for(i=0;i<n;++i)		
			scanf("%d",&a[i]);
		
		sort(a,a+n);
		for(i=1;i<n;++i)
		{
			while(!ans.empty())	ans.pop();
			for(j=0;j<n;++j)
				scanf("%d",&b[j]);
			sort(b,b+n);
			for(j=0;j<n;++j)			
				ans.push(a[j]+b[0]);
			
			for(j=1;j<n;++j)
			{
				ya=false;
				for(k=0;k<n;++k)
				{
					if(ans.top()>b[j]+a[k])
					{
						ans.pop();
						ans.push(b[j]+a[k]);
					}
					else
					{
						if(k==0)	ya=true;
						break;
					}
				}
				if(ya)	break;
			}

			for(j=n-1;j>=0;--j)
			{
				a[j]=ans.top();
				ans.pop();
			}
			
		}
		for(i=0;i<n;++i)
			printf("%d%c",a[i],i==n-1?'\n':' ');
	}
	return 0;
}