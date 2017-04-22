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

// #define MAXN 1100
// int k[MAXN];
// int s[MAXN];

int main()
{
    int T; scanf("%d", &T);
    int n,d;
    int k,s;
    double addtime=0;
    for(int tt = 1; tt <= T; tt++){
        addtime=0;
        printf("Case #%d: ", tt);
        scanf("%d%d",&d,&n);
        for(int i=0;i<n;++i){
            scanf("%d%d",&k, &s);
            addtime=addtime<(double)(d-k)/(double)s?(double)(d-k)/(double)s:addtime;
        }
        // Debug(addtime);
        printf("%lf\n",(double)d/(double)addtime);
    }


}