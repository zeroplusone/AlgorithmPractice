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

#define MAXN 110
int M[MAXN][MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    int N;
    set<int> row, col;
    for (int tt = 1; tt <= T; tt++)
    {
        int trace=0, rowAns=0, colAns=0;
        printf("Case #%d: ", tt);
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                scanf("%d", &M[i][j]);
                if (i==j) {
                    trace+=M[i][j];
                }
            }
        }

        for (int i = 1; i <= N; ++i)
        {
            row.clear();
            for (int j = 1; j <= N; ++j)
            {
                if (row.count(M[i][j]))
                {
                    rowAns++;
                    break;
                } else {
                    row.insert(M[i][j]);
                }
            }
        }

        for (int i = 1; i <= N; ++i)
        {
            col.clear();
            for (int j = 1; j <= N; ++j)
            {
                if (col.count(M[j][i]))
                {
                    colAns++;
                    break;
                }
                else
                {
                    col.insert(M[j][i]);
                }
            }
        }
        printf("%d %d %d\n", trace, rowAns, colAns);
    }

    return 0;
}
