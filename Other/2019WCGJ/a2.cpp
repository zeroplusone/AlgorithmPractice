/******
Solution 2. greedy
time complexity: O(N^2)
space complexity: O(N)
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

bool canbe(int st, int en)
{
    bool inc = false, des = false;
    for (int i = st + 1; i <= en; ++i)
    {
        if (m[i] - m[i - 1] > 0)
        {
            inc = true;
        }
        else if (m[i] - m[i - 1] < 0)
        {
            des = true;
        }
    }
    if (inc && des)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int solve(int st, int en)
{
    int diff = en - st;
    // base case
    if (diff <= 3)
    {
        return 0;
    }
    else
    {
        int ans = 0;

        for (int i = st + 2; i < en - 1; ++i)
        {
            if (canbe(st, i) && canbe(i, en))
            {
                ans = 1 + solve(i, en);
                break;
            }
        }
        return ans;
    }
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
        for (int i = 0; i < K + 1; ++i)
        {
            scanf("%d", &m[i]);
        }
        printf("%d\n", solve(0, K));
    }
    return 0;
}
