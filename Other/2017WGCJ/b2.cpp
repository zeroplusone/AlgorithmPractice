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

#define Fill(s,v) memset(s,v,sizeof(s))
#define Debug(x) cout << #x" = " << x <<endl;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

#define MAXN 100
#define EPS 0.000001
double ans;
bool v[MAXN];
double pmul[MAXN];
double p[MAXN];




int main()
{
    int n;
    int T; scanf("%d", &T);
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        ans=1;
        Fill(v,false);
        scanf("%d",&n);
        for (int i = 0; i < 2*n; ++i)
        {
            scanf("%lf",&p[i]);
        }
        sort(p,p+(2*n));
        for (int i = 0; i < n; ++i)
        {
            ans*=1-p[i]*p[2*n-i-1];
        }


        printf("%lf\n",ans);
    }


}