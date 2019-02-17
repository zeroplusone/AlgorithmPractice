/******
Solution 3. greedy
time complexity: O(N)
space complexity: O(1)
******/

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
int m[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    int K, ans;
    bool inc = false, dec = false;
    for (int tt = 1; tt <= T; tt++)
    {
        printf("Case #%d: ", tt);
        scanf("%d", &K);
        ans = 0;
        inc = false;
        dec = false;
        scanf("%d", &m[0]);
        for (int i = 1; i < K + 1; ++i)
        {
            scanf("%d", &m[i]);
            if (m[i] - m[i - 1] > 0)
            {
                inc = true;
            }
            else if (m[i] - m[i - 1] < 0)
            {
                dec = true;
            }
            if (inc && dec)
            {
                ans++;
                inc = false;
                dec = false;
            }
        }

        if (!(inc && dec))
            ans--;
        printf("%d\n", ans);
    }
    return 0;
}
