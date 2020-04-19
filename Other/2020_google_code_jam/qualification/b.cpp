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

// Nesting Depth
int main()
{
    int T;
    string S, ans;
    scanf("%d", &T);
    for (int tt = 1; tt <= T; tt++)
    {
        cin>>S;
        ans = "";
        int last = 0;
        int now;
        for(int i=0;i<S.length();++i){
            now = S[i]-'0';
            if(last>now) {
                for(int j=0;j<last-now;++j){
                    ans+=')';
                }
            }else if (last<now) {
                for (int j = 0; j < now-last; ++j)
                {
                    ans += '(';
                }
            }
            ans+=S[i];
            last = now;
        }

        if(last>0){
            for (int j = 0; j < last; ++j)
            {
                ans += ')';
            }
        }


        printf("Case #%d: ", tt);
        cout<<ans<<endl;
    }
}
