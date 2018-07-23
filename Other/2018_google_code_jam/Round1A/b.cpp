#include <bits/stdc++.h>
using namespace std;

#define ForN(i,n) for (i=0; i<n; i++)
#define For1N(i,n) for (i=1; i<=n; i++)
#define ForAB(i,a,b) for (i=a; i<=b; i++)
#define ForNR(i,n) for (i=(n)-1; i>=0; i--)
#define For1NR(i,n) for (i=n; i>0; i--)
#define ForABR(i,a,b) for (i=b; i>=a; i--)
#define ForBE(i,s) for (i=s.begin(); i!=s.end(); i++)

#define Fill(s,v) memset(s,v,sizeof(s))
#define Debug(x) cout << #x" = " << x <<endl;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

#define MAXB 50
#define INF 1000000000
long long int dp[2][MAXB];

int main()
{
    int T; scanf("%d", &T);
    long long int R, B, C;
    long long int M, S, P;
    long long int i, j, k;
    long long int limit;
    long long int longestTime, minans;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        scanf("%lld%lld%lld",&R, &B, &C);
        for(i=0;i<=B;++i){
            dp[0][i]= INF;
        }
        // printf("\n");
        for(i=0;i<C;++i){
            scanf("%lld%lld%lld",&M, &S, &P);
            // for(j=1;j<=B;++j){
            //     printf("%lld ", dp[0][j]);
            // }
            dp[0][0]=0;
            // printf("\n");
            for(j=1;j<=B;++j){
                limit=min(M, j);
                minans=INF;
                for(k=1;k<=limit;++k){
                    if(dp[0][j-k]==INF){
                        longestTime=INF;
                    }else{
                        longestTime=max(dp[0][j-k], k*S+P);
                    }
                    minans=longestTime<minans?longestTime:minans;
                }
                dp[1][j]=min(dp[0][j], minans);
            }
            for(j=1;j<=B;++j){
                dp[0][j]=dp[1][j];
            }
            
        }
        // for(j=1;j<=B;++j){
        //         printf("%lld ", dp[0][j]);
        //     }
        //     printf("\n");
        printf("%lld\n",dp[0][B]);
    }

    return 0;
}
