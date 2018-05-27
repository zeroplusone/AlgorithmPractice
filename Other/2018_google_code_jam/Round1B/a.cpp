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

#define MAXN 100010
int C[MAXN];
double dp[2][MAXN];
struct MODNS{
    int index;
    double remain;
    bool operator<(const MODNS& p)const{
        return remain<p.remain;
    }
}modn[MAXN];

int main()
{
    int T; scanf("%d", &T);
    int N, L;
    int sum;
    int roundn;
    double rnow;
    double divide;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        memset(C, 0, sizeof(C));
        sum=0;
        scanf("%d%d",&N, &L);
        for(int i=0;i<N;++i){
            modn[i].index=i;
            divide=(double)i/(double)N * 100;
            roundn=(int)(divide+0.5);
            if(roundn!=(int)(divide)){
                modn[i].remain=(int)(divide+0.5)-divide;
            }else{
                modn[i].remain=(-1)*(divide-(int)(divide));
            }
        }
        rnow=0;
        for(int i=1;i<=L;++i){
            scanf("%d",&C[i]);
            sum+=C[i];
            rnow+=modn[C[i]%N].remain;
        }

        for(int i=0;i<=N-sum;++i){
            dp[0][i]=rnow;
            dp[1][i]=-100;
        }
        for(int j=1;j<=L;++j){
            for(int i=1;i<=N-sum;++i){
                for(int k=0;k<=i;++k){
                    dp[1][i]=max(dp[1][i], dp[0][i-k]-modn[C[j]%10].remain+modn[(C[j]+k)%10].remain);
                }
            }
            for(int i=0;i<=N-sum;++i){
                dp[0][i]=dp[1][i];
            }
        }

        printf("%d\n", (int)(100+dp[0][N-sum]+0.5));
    }
    return 0;

}
