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

int main()
{
    int T;
    scanf("%d", &T);
    int divide[10][2] = {{0, 0}, {0, 1}, {1, 1}, {1, 2}, {2, 2}, {2, 3}, {3, 3}, {2, 5}, {3, 5}, {3, 6}};
    string s;
    char now;
    int len;
    bool first;
    for (int tt = 1; tt <= T; tt++)
    {
        printf("Case #%d: ", tt);
        cin >> s;
        len = s.length();
        first = true;
        for (int i = 0; i < len; ++i)
        {
            now = '0' + divide[s[i]-'0'][0];
            if (first)
            {
                if (now == '0')
                    continue;
                else
                {
                    printf("%c", now);
                    first = false;
                }
            }
            else
            {
                printf("%c", now);
            }
        }
        printf(" ");
        for (int i = 0; i < len; ++i)
        {
            now = '0' + divide[s[i]-'0'][1];
            if (first)
            {
                if (now == '0')
                    continue;
                else
                {
                    printf("%c", now);
                    first = false;
                }
            }
            else
            {
                printf("%c", now);
            }
        }
        printf("\n");
    }
    return 0;
}