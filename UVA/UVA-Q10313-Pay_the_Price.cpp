/******************
Judge   : uva
Problem : 10313 - Pay the Price
Course  : Course12
discribe:  how many ways one could pay a certain price using a limited number of coins
			When there is only one integer N as input, you should output in how many ways N dollars can be paid.

			When there are two integers N and L1 as input, then you should output in how many ways N dollars can be paid using L1 or less coins.

			When there are three integers N, L1 and L2 as input, then you should output in how many ways N dollars can be paid using L1, L1+1 …, L2 coins (summing all together). Remember that L1 is not greater than L2.
Input   :
			6
			6 3
			6 2 5
			6 1 6
Output  :
			11
			7
			9
			11
Solve   : coin problem
			總硬幣數有線，湊的到某價位的有幾種
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

#define MAXN 350
long long int dp[MAXN][MAXN];
int l[3];
char in[1000];

void build()
{
	memset(dp,0,sizeof(dp));
	int i,j,k;

	dp[0][0]=1;
	for(i=1;i<=300;++i)	//money
	{
		for(j=i;j<=300;++j)		//range
		{
			for(k=1;k<=j;++k)	//coin num(max $1 -> j)
			{
				dp[j][k]+=dp[j-i][k-1];
			}
		}
	}
}

int main()
{
	int i,type;
	long long int ans;
	int from,to;
	build();

	while(gets(in))
	{
		char* ptr,token[]=" \r\n";
		type=0;
		l[0]=l[1]=l[2]=0;

		for(ptr=strtok(in,token);ptr;ptr=strtok(NULL,token))
		{
			for(i=0;i<strlen(ptr);++i)
				l[type]=l[type]*10+ptr[i]-'0';
			type++;
		}

		switch(type)
		{
			case 1:
				from=0;
				to=l[0];
				break;
			case 2:
				from=0;
				to=l[0]<l[1]?l[0]:l[1];
				break;
			case 3:
				from=l[1];
				to=l[0]<l[2]?l[0]:l[2];
				break;
			default:
				break;
		}

		ans=0;
		for(i=from;i<=to;++i)
			ans+=dp[l[0]][i];
		printf("%lld\n",ans);
	}
	return 0;
}
