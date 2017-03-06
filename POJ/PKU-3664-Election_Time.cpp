/******************
Judge   : PKU
Problem : 3664-Election Time
Course  : Course1
discribe: first round highest K cows enter to second round
          the highest in 2 round win. Find the winner in election
Input   : N K
          a1 b1  //result
		  a2 b2
		   .
		   .
		  an bn
Output  : ans		  
Solve   : sort(structure)
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX 50100

struct cow
{
	int a,b;
	int id;
	bool operator<(const cow& t)const
	{
		return a>t.a;
	}
}c[MAX];

int main()
{
	int n,k;
	int i,ans,max;
	while(scanf("%d %d",&n,&k)!=EOF)
	{
		for(i=0;i<n;++i)
		{
			scanf("%d %d",&c[i].a,&c[i].b);
			c[i].id=i+1;
		}
		sort(c,c+n);
		ans=0;
		for(i=1;i<k;++i)
		{
			if(c[i].b>c[ans].b)			
				ans=i;
			
		}
		printf("%d\n",c[ans].id);
	}
	return 0;
}