/******
Solution 1. naive: list all possibilities
time complexity: O(4^n)
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

#define MAXN 110
int ans[MAXN][MAXN];
bool visited[MAXN][MAXN];
bool v[MAXN][MAXN];
bool isFindAns;
int R, C, K;
char dir[4] = {'S', 'E', 'W', 'N'};
int opp[4] = {3, 2, 1, 0};
int step[4][2] = {
    {1, 0},
    {0, 1},
    {0, -1},
    {-1, 0}};

void printAns()
{
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            printf("%c", dir[ans[i][j]]);
        }
        printf("\n");
    }
}

bool walkout(int r, int c)
{
    // not escape: walk to visited
    // escpae: index out of boundary
    memset(v, false, sizeof(v));
    int orir, oric;
    while ((r >= 0 && r < R) && (c >= 0 && c < C))
    {
        if (v[r][c])
        {
            return false;
        }
        v[r][c] = true;
        orir = r;
        oric = c;
        
        r += step[ans[orir][oric]][0];
        c += step[ans[orir][oric]][1];
    }
    return true;
}

//TODO
bool check()
{
    int escapeN = 0;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (walkout(i, j))
                escapeN++;
        }
    }
    if (escapeN == K)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void print()
{
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            printf("%c", dir[ans[i][j]]);
        }
        printf("\n");
    }
}

void solve(int now)
{
    // base case
    if (now == R * C)
    {
        // print();
        if (check())
        {
            isFindAns = true;
        }
        return;
    }
    // recursive
    int r = now / C;
    int c = now % C;
    int newr, newc;
    for (int i = 0; i < 4; ++i)
    {
        if (isFindAns)
            return;
        newr = r + step[i][0];
        newc = c + step[i][1];
        if (((newr < 0 || newr >= R) || (newc < 0 || newc >= C)) || (!visited[newr][newc] || i != opp[ans[newr][newc]]))
        {
            ans[r][c] = i;
            visited[r][c] = true;
            solve(now + 1);
            visited[r][c] = false;
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int tt = 1; tt <= T; tt++)
    {
        printf("Case #%d: ", tt);
        isFindAns = false;
        Fill(ans, -1);
        Fill(visited, false);
        scanf("%d %d %d", &R, &C, &K);
        solve(0);
        if (isFindAns)
        {
            printf("POSSIBLE\n");
            printAns();
        }
        else
        {
            printf("IMPOSSIBLE\n");
        }
    }
    return 0;
}
