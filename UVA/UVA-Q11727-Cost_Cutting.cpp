/******************
Judge   : UVA
Problem : 11727-Cost_Cutting.cpp
Course  : Course1
discribe: 3 people fine the money in the middle
Input   : t
          (s0 s1 s2)*n
		  
Output  : Case n: s1
Solve   : sort
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	int i;
	int s[3];
	int ans;
	while(scanf("%d",&t)!=EOF)
	{
		for(i=1;i<=t;++i)
		{
			scanf("%d%d%d",&s[0],&s[1],&s[2]);
			/*(1) sort(s,s+3);
			printf("Case %d: %d\n",i,s[1]);*/
			/*(2)*/
			
			if(s[0]<=s[1] && s[0]<=s[2])
				ans=s[1]>s[2]?s[2]:s[1];
			else if(s[0]<=s[1] && s[0]>s[2])
				ans=s[0];
			else if(s[0]>s[1] && s[0]<=s[2])
				ans=s[0];
			else if(s[0]>s[1] && s[0]>s[2])
				ans=s[1]>s[2]?s[1]:s[2];
			printf("Case %d: %d\n",i,ans);
		}
		
	}
	return 0;
}