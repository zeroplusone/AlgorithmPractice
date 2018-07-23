// solution 1 from analysis 
// https://code.google.com/codejam/contest/10284486/dashboard#s=a&a=0

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

long long int calAns(long long int n){
    long long int x0=n%10, ans=0,i, tmp, C, nine;
    bool hasnine=false;
    for(i=n-x0;i<=n;++i){
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
    Debug(ans)
    C=0;
    nine=9;
    n/=10;
    while(n>0){
        C+=n%10*nine;
        nine*=9;
        n/=10;
    }
    ans+=C*8/9;
    Debug(ans)
    return ans;
}

int main()
{
    int T; scanf("%d", &T);
    long long int F, L;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        scanf("%lld%lld",&F, &L);
        printf("%lld\n",calAns(L)-calAns(F)+1);

    }

    return 0;
}
