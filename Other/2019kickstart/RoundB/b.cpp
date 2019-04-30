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
#include <unordered_map>
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
int S[MAXN];
int E[MAXN];
int L[MAXN];
bool v[MAXN];
int N;
int ans;

void backtrack(int now, int sum, int t){
    // cout<<now<<" "<<sum<<" "<<t<<endl;
    if(now==N){
        ans=sum>ans?sum:ans;
        return;
    }
    int cal;
    for(int i=0;i<N;++i){
        if(!v[i]){
            v[i]=true;
            cal = E[i] - L[i] * t;
            backtrack(now + 1, sum+(cal<0?0:cal), t + S[i]);
            v[i]=false;
        }
    }
}



int main()
{
    int T;
    scanf("%d", &T);

    for (int tt = 1; tt <= T; tt++)
    {
        scanf("%d", &N);
        printf("Case #%d: ", tt);
        for(int i=0;i<N;++i){
            scanf("%d%d%d",&S[i],&E[i],&L[i]);
        }
        memset(v,false,sizeof(v));
        ans=0;
        backtrack(0, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}