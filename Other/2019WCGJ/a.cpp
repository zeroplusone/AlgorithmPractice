/******
Solution 1. list all possible and check
time complexity: O(2^n)
space complexity: O(n)
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
bool post[MAXN];
int ans;

void print(int n)
{
    for (int i = 0; i <= n; ++i)
    {
        if (post[i])
            cout << "1";
        else
            cout << "0";
    }
    cout << endl;
}

void solve(int now, int n)
{
    if (now == n)
    {
        int count = 0;
        bool inc = false, des = false;
        for (int i = 1; i <= n; ++i)
        {
            if (m[i] - m[i - 1] > 0)
            {
                inc = true;
            }
            else if (m[i] - m[i - 1] < 0)
            {
                des = true;
            }
            if (post[i])
            {
                if (!(inc && des))
                    return;
                count++;
                inc = false;
                des = false;
            }
        }
        count--;
        ans = count > ans ? count : ans;
        return;
    }
    post[now] = true;
    solve(now + 1, n);
    post[now] = false;
    solve(now + 1, n);
}
int main()
{
    int T;
    scanf("%d", &T);
    int K;
    for (int tt = 1; tt <= T; tt++)
    {
        printf("Case #%d: ", tt);
        scanf("%d", &K);
        ans = 0;
        memset(post, false, sizeof(post));
        post[0] = post[K] = true;
        for (int i = 0; i < K + 1; ++i)
        {
            scanf("%d", &m[i]);
        }
        solve(1, K);
        printf("%d\n", ans);
    }
    return 0;
}
