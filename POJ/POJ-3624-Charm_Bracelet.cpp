/******************
 Judge   : POJ
 Problem : 3624-Charm Bracelet
 Course  : Course8
 discribe: 0/1 Knapsck
 Input   :
 4 6    // n items m package size
 1 4    //weight price
 2 6
 3 12
 2 7
 26
 Output  :
 23
 Solve   : 0/1 Knapsack
 *****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
#define MAXN 3500
#define MAXB 13000
int w[MAXN];
int p[MAXN];
/*
int dp[MAXN][MAXB];

void builddp(int n,int m)
{
    
    int i,j;
    memset(dp,0,sizeof(dp));
    for(i=1;i<=n;++i)
    {
        for(j=0;j<=m;++j)
        {
            if(j-w[i]>=0)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+p[i]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
}
*/
int dp[MAXB];

void builddp(int n,int m)
{
    
    int i,j;
    memset(dp,0,sizeof(dp));
    for(i=1;i<=n;++i)
    {
        for(j=m;j>=0;--j)
        {
            if(j-w[i]>=0)
                dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
            else
                dp[j]=dp[j];
        }
    }
}


int main()
{
    int n,m;
    int i;

    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;++i)
            scanf("%d%d",&w[i],&p[i]);
        
        builddp(n,m);
        printf("%d\n",dp[m]);

    }
    return 0;
}
