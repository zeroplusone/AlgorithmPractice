#define MAX 110
long long int dp[MAX][MAX];
long long int c(int a,int b)
{
    if(a>=0 && b>=0 && dp[a][b])
        return dp[a][b];
    else if(a==b)
        dp[a][b]=1;
    else if(a<b)
        dp[a][b]=0;
    else if(a<=1)
        dp[a][b]=1;
    else if(b==1)
        dp[a][b]=a;
    else if(b==0)
        dp[a][b]=1;
    else{
        int tmp=b;
        if(b*2>a)
            tmp=a-b;
        dp[a][b]=c(a-1,tmp)+c(a-1,tmp-1);
    }
    return dp[a][b];
}