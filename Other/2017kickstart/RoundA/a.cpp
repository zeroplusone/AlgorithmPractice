#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;

typedef long long ll;
#define MAX 2000
#define MOD 1000000007
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
    else
    {
        int tmp=b;
        if(b*2>a)
            tmp=a-b;
        dp[a][b]=(c(a-1,tmp)+c(a-1,tmp-1))%MOD;
    }
    return dp[a][b]%MOD;
}

int main()
{
    int casenum;
    ll ans;
    int R,C,minRC;
    scanf("%d",&casenum);

    for(int cc=1;cc<=casenum;++cc)
    {
        printf("Case #%d: ",cc);
        scanf("%d%d",&R,&C);
        minRC=min(R,C);
        ans=0;
        for(int i=1;i<minRC;++i){
            ans+=(R-i)*(C-i)%MOD;
        }
        for(int i=2;i<minRC;++i){
            ans+=(i-1)*(C-i)%MOD*(R-i)%MOD;
        }
        ans%=MOD;
        
        printf("%lld\n",ans);
    }
    return 0;
}
