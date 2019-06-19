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

#define MAXN 305
int dp[MAXN][MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    int ans;
    int r,c,k;
    int last, cnt, input;
    for (int tt = 1; tt <= T; tt++)
    {
        ans=1;
        scanf("%d%d%d",&r, &c, &k);

        for (int i = 0; i < r; ++i)
        {
            last=-1; cnt=-1;
            for (int j = 0; j < c; ++j)
            {
                scanf("%d",&input);
                cout<<input<<" " <<last<<" "<<cnt<<endl;
                if(input!=last){
                    cnt++;
                    last=input;
                }
                dp[i][j]=cnt;
            }
        }

        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                printf("%d%c",dp[i][j], j==c-1?'\n':' ');
            }
        }

        printf("Case #%d: ", tt);

        printf("%d\n", ans);
    }
    return 0;
}