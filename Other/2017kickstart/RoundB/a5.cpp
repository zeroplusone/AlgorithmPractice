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

#define MAXN 100010
#define MOD 1000000007
int k[MAXN];

LL f_pow(int a,int b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%MOD;
        temp=temp*temp%MOD;
        b>>=1;
    }
    return res;
}

int main()
{
    int T; scanf("%d", &T);
    int n;
    int l,r;
    long long int ans, diff;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        scanf("%d",&n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d",&k[i]);
        }
        ans=0;
        for (int i = 0; i < n; ++i)
        {
            for(int j=i+1;j<n;++j){
                ans=(ans+(k[j]-k[i])*f_pow(2,j-i-1)%MOD)%MOD;
                //Debug(ans)
            }
        }
        printf("%lld\n",ans);
    }


}