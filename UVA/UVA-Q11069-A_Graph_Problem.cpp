/******************
Judge   : UVA
Problem : 755-487--3279
Course  : Course2
discribe: in 1-2-3-...-n  graph 
		find how many subsets that 
		1.no nodes in the subset should be connected
		2.it shouldn't be possible to add further nodes to the subset without violating the first condition
		
Input   : n
        
          n
Output  : ans
		  ans
		  .
		  .
		  ans
Solve   : recursive-> dp
*******************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int n;
#define MAXN 80
int dp[MAXN];
/*
bool used[MAXN];
int ans;
//only walk n+2 or n+3
void com2(int now,bool ya)
{
	if(now==n)
	{
		ans++;
		return;
	}
	if(now+2>n)
	{
		if(ya)
			com2(n,ya);
		return;
	}
	else
		com2(now+2,true);
	if(now+3>n)
		return;
	else
		com2(now+3,true);
}
*/
//can count from before

int main()
{
	dp[1]=1;	dp[2]=2;	dp[3]=2;
	int i;
	for(i=4;i<78;++i)
		dp[i]=dp[i-2]+dp[i-3];
		
	while(scanf("%d",&n)!=EOF)
	{
		/*ans=0;
		memset(used,false,sizeof(used));
		com2(1,true);
		if(n>1)
			com2(2,true);
		printf("%d\n",ans);*/
		printf("%d\n",dp[n]);
	}
	return 0;
}