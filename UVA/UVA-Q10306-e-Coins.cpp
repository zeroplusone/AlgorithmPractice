/******************
Judge   : uva
Problem : 10306 - e-Coins
Course  : Course12
discribe: e-modulus is SQRT(X*X+Y*Y)
		  calculates the smallest amount of e-coins that are needed to exactly match the e-modulus.
		   no limit on how many e-coins of each type that may be used to match the given e-modulus.
Input   :
			3 		//n(#case~100)
			2 5 	//m(#cash type~40) S(question value~300)
			0 2 	//x1 y1
			2 0
			3 20 	//m  s
			0 2
			2 0
			2 1
			3 5 	//m  s
			3 0
			0 4
			5 5
Output  :
			not possible
			10
			2
Solve   : 0/1 Knapsack
		無限，求最小花費
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

#define MAXM 50
#define MAXS 310
#define INF 9999999
int x[MAXM],y[MAXM];
int dp[MAXS][MAXS];	//dp[i][j] x=i,y=j 有幾個
int m,s;
int ans;
void builddp()
{
		int i,j,k;
		int tmp;
		for(i=0;i<=s;++i)
			for(j=0;j<=s;++j)
				dp[i][j]=INF;
		dp[0][0]=0;
		ans=INF;
		for(i=0;i<m;++i)	//type
		{
			for(j=x[i];j<=s;++j)	//x
			{
				for(k=y[i];k<=s;++k)
				{
					if(dp[j-x[i]][k-y[i]]!=INF)
					{
						dp[j][k]=min(dp[j][k],dp[j-x[i]][k-y[i]]+1);
						if(j*j+k*k==s*s)
						{
							ans=min(ans,dp[j][k]);
							//printf("%d %d %d\n",j,k,dp[j][k]);
						}

					}
				}
			}
		}
}

int main()
{
	int t;
	int i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&s);
		for(i=0;i<m;++i)
			scanf("%d%d",&x[i],&y[i]);
		builddp();
		/*for(i=0;i<=s*s;++i)
			printf("%d ",dp[m][i]);
		printf("\n");*/
		if(ans==INF)	//to find min ,setINF
			printf("not possible\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
