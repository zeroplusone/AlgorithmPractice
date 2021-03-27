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

int main()
{
    int T;
    scanf("%d", &T);
    int X, Y;
    string s;
    int ans;
    for (int tt = 1; tt <= T; tt++)
    {
        ans=0;
        scanf("%d%d", &X, &Y);
        cin >> s;
        int st = 0, en = s.length() - 1;
        while (st <= en && s[st] == '?')
        {
            st++;
        }
        while (en >= st && s[en] == '?')
        {
            en--;
        }
        int next;
        for(int i=st;i<en;) {
            next=i+1;
            while(next<en && s[next]=='?') {
                next++;
            }
            if(s[i]=='C' && s[next]=='J') {
                ans+=X;
            } else if(s[i]=='J' && s[next]=='C') {
                ans+=Y;
            }
            i=next;
        }

        printf("Case #%d: ", tt);
        printf("%d\n", ans);
    }
}
