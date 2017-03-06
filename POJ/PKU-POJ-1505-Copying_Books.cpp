/******************
Judge   : POJ
Problem : POJ-1505-Copying Books
Course  : IOI
discribe: m book writen by k man
		  find the minimun of (max of the pages) 
			
Input   : 
			2	//
			9 3
			100 200 300 400 500 600 700 800 900
			5 4
			100 100 100 100 100
Output  : 
			100 200 300 400 500 / 600 700 / 800 900
			100 / 100 / 100 / 100 100
Solve   : DP
*******************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXK 510

int dp[MAXK][MAXK];
int cut[MAXK];
int sum[MAXK];
int ans[MAXK][MAXK];

int solve(int j,int i)
{
	if(dp[j][i]!=0)
		return dp[j][i];

		int v,tmp,minval;
	if(i>j)	dp[j][i]=solve(j,i-1);
				else
				{
					minval=solve(j,i-1);	//**************************
					for(v=j-1;v>=i-1;--v)	//from end to start
					{
						tmp=solve(v,i-1);
						tmp=tmp>(sum[j]-sum[v])?tmp:(sum[j]-sum[v]);
						
						if(minval>=tmp)
						{
							
							minval=tmp;
							//ans[j][i]=v;
						}
					}
					dp[j][i]=minval;
				}
	return dp[j][i];
}

int main()
{
	int n;
	int m,k,in;
	int i,j,v,tmp;
	int minval;
	scanf("%d",&n);
	while(n--)
	{
		memset(sum,0,sizeof(sum));
		memset(cut,0,sizeof(cut));
		memset(ans,0,sizeof(ans));
		memset(dp,0,sizeof(dp));
		
		scanf("%d %d",&m,&k);
		for(i=1;i<=m;++i)
		{
			scanf("%d",&in);
			sum[i]=sum[i-1]+in;
			dp[i][1]=sum[i];
		}
		
	/*	for(i=2;i<=k;++i)
		{
			for(j=1;j<=m;++j)
			{
				if(i>j)	dp[j][i]=dp[j][i-1];
				else
				{
					minval=dp[j][i-1];	//**************************
					for(v=j-1;v>=i-1;--v)	//from end to start
					{
						tmp=dp[v][i-1]>(sum[j]-sum[v])?dp[v][i-1]:(sum[j]-sum[v]);
						
						if(minval>=tmp)
						{
							
							minval=tmp;
							//ans[j][i]=v;
						}
					}
					dp[j][i]=minval;
				}
			}
		}
		*/
		solve(m,k);
		tmp=0;

		for(i=m,j=k-1;i>0 && j>0;--i)
		{
			tmp+=sum[i]-sum[i-1];
			if(tmp>dp[m][k] || j>=i)
			{
				cut[j]=i;
				tmp=sum[i]-sum[i-1];
				j--;
			}
		}
/* WA ex.1 1 1 1 9 -> 1 1 / 1 1 / 9  
		for(i=m,j=k;i>0 && j>1;--j)
		{
			cut[j-1]=ans[i][j];
			i=ans[i][j];

		}
*/
		
		for(i=1,j=1;i<=m;++i)
		{
			if(i!=1)	printf(" ");
			printf("%d",sum[i]-sum[i-1]);
			if(j<k && i==cut[j])
			{
				printf(" /");
				j++;
			}
		}
		printf("\n");
	}
	return 0;
}