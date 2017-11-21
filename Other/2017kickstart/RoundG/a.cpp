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


long long int bigmod(int x, int n, int p) {
    if (n == 0) return 1 % p;
    if(n==1) return x%p;
    long long int a = bigmod(x, n/2, p);
    return a*a%p*(n%2? x : 1)%p;
}

int main()
{
    int T; scanf("%d", &T);
    long long int a, n, t, ans;

    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        scanf("%lld%lld%lld",&a,&n,&t);
        ans = 1;
        for(int i=n;i>0;--i){
            ans=(ans*bigmod(a,i,t))%t;
            //printf("%lld %lld %lld %d\n", ans, bigmod(a,i,t), a, i);
            a = ans;
        }
        printf("%lld\n", ans);
    }
}

