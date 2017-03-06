/******************
Judge   : POJ
Problem : 2442-Sequence.cpp
Course  : Course6
discribe:  pick exactly one element in each array and calculate the sum of the integers. Your task is to find the k smallest sums among them.
Input   : 	1		//t(case)
		==========
			2 3		//n*n array
			1 2 3	//arry
			2 2 3
			
Output  : 	3 3 4 //1+2 1+2 2+2
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

#define MAXN 2100
int a[MAXN],b[MAXN];

int main()
{
	int t;
	int n,m;
	int i,j,k;
	int tmp;
	bool ya=false;
	priority_queue<int> ans;	
	
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			scanf("%d%d",&m,&n);
			while(!ans.empty())	ans.pop();
			for(i=0;i<n;++i)		
				scanf("%d",&a[i]);
			
			sort(a,a+n);
			for(i=1;i<m;++i)
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
	}
	return 0;
}