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

#define MAXN 60
char str[MAXN][MAXN];
struct Answer{
    int order;
    char s[MAXN];
    bool operator<(const Answer A)const{
        return order<A.order;
    }
}ans[MAXN];

int main()
{
    int T; scanf("%d", &T);
    LL N, K, V, index;
    for(int tt = 1; tt <= T; tt++){
        scanf("%lld%lld%lld", &N, &K, &V);
        for(int i=0;i<N;++i){
            scanf("%s",str[i]);
            getchar();
        }
        index = K*(V-1)%N;
        printf("Case #%d:", tt);
        for(int i=0;i<K;++i){
            strcpy(ans[i].s, str[(index+i)%N]);
            ans[i].order=(index+i)%N;
        }
        sort(ans, ans+K);
        for(int i=0;i<K;++i){
            printf(" %s",ans[i].s);
        }
        printf("\n");
    }

    return 0;
}
