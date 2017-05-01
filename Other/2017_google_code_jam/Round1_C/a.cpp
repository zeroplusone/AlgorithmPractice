#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
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
#define PI acos(-1)
#define MAXN 1100

struct answer{
    double face;
    int panNum;
}dp[MAXN][MAXN];

struct pan{
    double h;
    double r;
    bool operator<(const struct pan &pp)const{
        return r==pp.r?h>pp.h:r>pp.r;
    }
}p[MAXN];

int main()
{
    int T; scanf("%d", &T);
    int n, k;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        scanf("%d%d",&n,&k);
        for(int i=0;i<=n;++i){
            for(int j=0;j<=n;++j){
                dp[i][j].face=0;
                dp[i][j].panNum=0;
            }
        }
        for(int i=0;i<n;++i){
            scanf("%lf%lf",&p[i].r, &p[i].h);
        }
        sort(p,p+n);
        double choose=0;
        for(int i=1;i<=k;++i){
            for(int j=1;j<=n;++j){
                if(j<i){
                    // if(i==1){
                    //     dp[i][j].face+=p[j-1].r*p[j-1].r*PI;
                    // }
                    // dp[i][j].face+=2*p[j-1].r*PI*p[j-1].h;
                    // dp[i][j].panNum=dp[i-1][j-1].panNum+1;
                }else{
                    choose=0;
                    if(i==1){
                        choose+=p[j-1].r*p[j-1].r*PI;
                    }
                    choose+=2*p[j-1].r*PI*p[j-1].h;

                    dp[i][j].face=dp[i-1][j-1].face+choose;
                    for(int jj=i;jj<j;++jj){
                        dp[i][j].face=max(dp[i][j].face, dp[i][jj].face);
                    }
                }
                
            }
        }
        // printf("\n");
        // for(int i=0;i<=k;++i){
        //     for(int j=0;j<=n;++j){
        //         printf("%lf ",dp[i][j].face);
        //     }
        //     printf("\n");
        // }

        printf("%.9lf\n", dp[k][n].face);
    }


}