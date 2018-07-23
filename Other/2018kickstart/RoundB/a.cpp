// only pass for small tests

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

int main()
{
    int T; scanf("%d", &T);
    long long int F, L, ans, i, tmp;
    bool hasnine;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        scanf("%lld%lld",&F, &L);
        //ans=((L-L%9)-(F-F%9))/9+
        ans=0;
        for(i=F;i<=L;++i){
            if(i%9==0)
                continue;
            tmp=i;
            hasnine=false;
            while(tmp>0){
                if(tmp%10==9){
                    hasnine=true;
                    break;
                }
                tmp/=10;
            }
            if(hasnine)
                continue;
            ans+=1;
        }
        printf("%lld\n",ans);
    }


}
