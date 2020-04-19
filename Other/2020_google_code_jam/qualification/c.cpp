#include <bits/stdc++.h>
using namespace std;

#define ForN(i, n) for (i = 0; i < n; i++)
#define For1N(i, n) for (i = 1; i <= n; i++)
#define ForAB(i, a, b) for (i = a; i <= b; i++)
#define ForNR(i, n) for (i = (n)-1; i >= 0; i--)
#define For1NR(i, n) for (i = n; i > 0; i--)
#define ForABR(i, a, b) for (i = b; i >= a; i--)
#define ForBE(i, s) for (i = s.begin(); i != s.end(); i++)

#define Fill(s, v) memset(s, v, sizeof(s))
#define Debug(x) cout << #x " = " << x << endl;

#define LL long long
#define LD long double
#define PR pair<int, int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

#define MAXN 1100

struct ACTIVITY {
    int id;
    int st;
    int en;
    bool operator<(const ACTIVITY& a) const{
        return st==a.st?en>a.en:st<a.st;
    }
}ac[1100];

int main()
{
    int T;
    int N;
    scanf("%d", &T);
    for (int tt = 1; tt <= T; tt++)
    {
        string ans = "";
        int c=-1, j=-1;
        scanf("%d", &N);
        for(int i=0;i<N;++i){
            ac[i].id=i;
            scanf("%d%d", &ac[i].st, &ac[i].en);
            ans+='.';
        }
        sort(ac, ac+N);
        for (int i = 0; i < N; ++i)
        {
            if(c<=ac[i].st) {
                c=ac[i].en;
                ans[ac[i].id]='C';
            } else if (j <= ac[i].st) {
                j = ac[i].en;
                ans[ac[i].id] = 'J';
            } else {
                ans = "IMPOSSIBLE";
                break;
            }
        }

        printf("Case #%d: ", tt);
        cout<<ans<<endl;
    }
}
