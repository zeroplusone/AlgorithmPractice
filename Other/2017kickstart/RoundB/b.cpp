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

#define ForN(i,n) for (i=0; i<n; i++)
#define For1N(i,n) for (i=1; i<=n; i++)
#define ForAB(i,a,b) for (i=a; i<=b; i++)
#define ForNR(i,n) for (i=(n)-1; i>=0; i--)
#define For1NR(i,n) for (i=n; i>0; i--)
#define ForABR(i,a,b) for (i=b; i>=a; i--)
#define ForBE(i,s) for (i=s.begin(); i!=s.end(); i++)

#define Fill(s,v) memset(s,v,sizeof(s))
#define Debug(x) cout << #x" = " << x <<endl;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

#define MAXN 110

struct POINT{
    double x, y, w;
}p[MAXN];

int main()
{
    int T; scanf("%d", &T);
    int n;
    double maxv;
    double ans=200000000;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%lf%lf%lf",&p[i].x, &p[i].y,&p[i].w);
        }

        ans=200000000;
        for(int i=0;i<n;++i){
            maxv=0;
            for(int j=0;j<n;++j){
                if(i!=j){
                    maxv+=max(abs(p[i].x-p[j].x), abs(p[i].y-p[j].y))*p[i].w;
                }
            }
            Debug(i)
            Debug(maxv)
            ans=maxv<ans?maxv:ans;
        }
        printf("%lf\n",ans);
    }


}