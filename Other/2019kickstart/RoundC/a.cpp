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

#define MAXN 50002
// E S N W
int dir[4][2]={{0, 1}, {1, 0}, {-1,0},{0,-1}};
bitset<50001> v[MAXN];
int main()
{
    int T;
    scanf("%d", &T);
    int N, r, c, d, sr, sc;
    char ch;
    for (int tt = 1; tt <= T; tt++)
    {
        //memset(v, false, sizeof(v));
        scanf("%d%d%d%d%d",&N, &r, &c, &sr, &sc);
        bitset<50001> b(0);
        for(int i=1;i<r+1;++i){
            v[i].reset();
        }

        v[sr].set(sc);
        getchar();
        while(N--){
            ch = getchar();
            switch(ch){
                case 'N':
                    d=2;
                    break;
                case 'S':
                    d=1;
                    break;
                case 'E':
                    d=0;
                    break;
                case 'W':
                    d=3;
                    break;
            }
            do
            {
                sr += dir[d][0];
                sc += dir[d][1];
            } while (v[sr].test(sc));
            v[sr].set(sc);
        }
        
        printf("Case #%d: ", tt);
        printf("%d %d\n", sr, sc);
    }
    return 0;
}