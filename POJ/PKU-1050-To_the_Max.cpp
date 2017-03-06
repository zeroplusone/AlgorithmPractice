/******************
Judge   : POJ
Problem : 1050-To the Max
Course  : Course9
discribe: max sub-rectangle
			
Input   : 
			4	//n
			0 -2 -7 0 9 2 -6 2		//n*n
			-4 1 -4  1 -1

			8  0 -2
Output  : 
			15	//max sub-rectangle sum
Solve   : dp
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 110
//int num[MAXN][MAXN];
int sum[MAXN][MAXN];
int mss[MAXN];
int main()
{
	int n;
	int i,j,k,in;
	int ans;
	while(scanf("%d",&n)!=EOF)
	{
		//memset(num,0,sizeof(num));
		memset(sum,0,sizeof(sum));
		ans=0;
		for(i=1;i<=n;++i)
		{		
			for(j=1;j<=n;++j)			
			{	
				scanf("%d",&in);
				sum[i][j]=sum[i][j-1]+in;
			}
		}	
		for(i=1;i<=n;++i)
		{
			for(j=i;j<=n;++j)
			{
				for(k=1;k<=n;++k)
				{
					in=sum[k][j]-sum[k][i-1];
					mss[k]=mss[k-1]>0?mss[k-1]+in:in;
					ans=mss[k]>ans?mss[k]:ans;
					//printf("%d to %d : mss[%d]= %d\n",i,j,k,mss[k]);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}