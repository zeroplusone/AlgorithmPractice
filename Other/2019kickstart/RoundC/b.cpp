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
int v[MAXN][MAXN];
int thick[MAXN][MAXN];
int cnt=0;
int r, c, k;
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

void dfs(int x, int y, int val){
    cnt++;
    v[x][y]=true;
    int nx, ny;
    for(int i=0;i<4;++i){
        nx=x+dir[i][0];
        ny=y+dir[i][1];
        if(nx>=0 && nx<r && ny>=0 && ny<c){
            if(!v[nx][ny] && thick[nx][ny]==val){
                dfs(nx, ny, val);
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    int ans;
    for (int tt = 1; tt <= T; tt++)
    {
        ans=1;
        memset(v, false, sizeof(v));
        scanf("%d%d%d",&r, &c, &k);

        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                scanf("%d",&thick[i][j]);
            }
        }

        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                if(!v[i][j]){
                    cnt=0;
                    dfs(i, j, thick[i][j]);
                    ans=max(ans, cnt);
                }
            }
        }

        printf("Case #%d: ", tt);

        printf("%d\n", ans);
    }
    return 0;
}