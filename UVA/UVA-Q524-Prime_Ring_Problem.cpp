/******************
Judge   : UVA
Problem : 524 - Prime Ring Problem
Course  : Course7
discribe:  A ring is composed of n (even number) circles,and the sum of numbers in two adjacent circles should be a prime.
			 beginning from 1 clockwisely and anticlockwisely. 
Input   : 	
			6  //n
			8
Output  : 	
Case 1:
			1 4 3 2 5 6
			1 6 5 2 3 4

			Case 2:
			1 2 3 8 5 6 7 4
			1 2 5 8 3 4 7 6
			1 4 7 6 5 8 3 2
			1 6 7 4 3 8 5 2
Solve   :	backtracking
*******************/
#include<bits/stdc++.h>
using namespace std;

#define MAXN 20
bool prime[2*MAXN];
int ans[MAXN];
bool v[MAXN];
int n;

void back(int now)
{
	int i;
	if(now==n && prime[ans[0]+ans[now-1]])
	{
		for(i=0;i<n;++i)
			printf("%d%c",ans[i],i==n-1?'\n':' ');
		return ;
	}
	for(i=1;i<=n;++i)
	{
		if(!v[i] && prime[ans[now-1]+i])
		{
			v[i]=true;
			ans[now]=i;
			back(now+1);
			v[i]=false;
		}
	}
}

int main()
{
	int i,j;
	int num=1;

	memset(prime,false,sizeof(prime));
	prime[2]=prime[3]=prime[5]=prime[7]=prime[11]=prime[13]=true;
	prime[17]=prime[19]=prime[23]=prime[29]=prime[31]=prime[37]=true;
	ans[0]=1;
	while(scanf("%d",&n)!=EOF)
	{
		memset(v,false,sizeof(v));
		if(num!=1)	printf("\n");
		printf("Case %d:\n",num++);
		v[1]=true;
		back(1);
	}
	return 0;
}