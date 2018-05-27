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

#define PRIME 1000000007

int Add(int a,int b, int MOD)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
    return(a);
}

int Mult(int a,int b, int MOD)
{
    return((LL)a*b%MOD);
}

#define MAXN 1000010
#define MAXK 10010
LL A[MAXN];
LL num[MAXN];

int main()
{
    int T; scanf("%d", &T);
    LL N, K, x1, y1, C, D, E1, E2, F, x, y, ans, base;
    for(int tt = 1; tt <= T; tt++){
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&N, &K, &x1, &y1, &C, &D, &E1, &E2,&F);
        // A[1]=Add(x1, y1, F);
        A[1]=(x1+y1)%F;
        for(int i=2;i<=N;++i){
            // x=Add(Add(Mult(C,x1,F),Mult(D, y1,F),F), E1, F);
            // y=Add(Add(Mult(D,x1,F),Mult(C, y1,F),F), E2, F);
            // A[i]= Add(x,y,F);
            x=(C*x1%F+D*y1%F+E1)%F;
            y=(D*x1%F+C*y1%F+E2)%F;
            A[i]=(x+y)%F;
            x1=x;
            y1=y;
        }

        for(int i=1;i<=N;++i){
            num[i]=0;
            base=i;
            for(int j=1;j<=K;++j){
                //num[i]=Add(num[i], base, PRIME);
                //base=Mult(base, i, PRIME);
                num[i]=(num[i]+base)%PRIME;
                base=(base*i)%PRIME;
            }
        }
        ans=0;
        for(int i=1;i<=N;++i){
            for(int j=1;j<=i;++j){
                // Debug(i)
                // Debug(j)
                // Debug(A[i])
                // Debug(1+N-i)
                // Debug(num[j])
                // ans=Add(ans, Mult(Mult(A[i], 1+N-i, PRIME),num[j], PRIME), PRIME);
                ans=(ans+((A[i]*(1+N-i)%PRIME)*num[j]%PRIME))%PRIME;
            }
        }
        printf("Case #%d: ", tt);
        printf("%lld\n", ans);
    }
    return 0;

}
