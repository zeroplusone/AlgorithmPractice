#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
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

#define MAXN 100100
#define MAX_VALUE 1000001000
int S[MAXN];
int main()
{
    int T;
    scanf("%d", &T);
    int n, p, ans, sum;
    for (int tt = 1; tt <= T; tt++)
    {
        memset(S, 0, sizeof(S));
        ans = MAX_VALUE;
        sum = 0;
        scanf("%d%d", &n, &p);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &S[i]);
        }
        sort(S, S + n);
        for (int i = 0; i < p - 1; ++i)
        {
            sum += S[p - 1] - S[i];
        }
        ans = sum < ans ? sum : ans;
        for (int i = p; i < n; ++i)
        {
            sum -= S[i - 1] - S[i - p];
            sum += (S[i] - S[i - 1]) * (p - 1);
            ans = sum < ans ? sum : ans;
        }
        printf("Case #%d: ", tt);

        printf("%d\n", ans);
    }
    return 0;
}