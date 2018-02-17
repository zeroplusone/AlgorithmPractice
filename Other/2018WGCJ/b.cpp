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

#define MAXN 1100

struct Level{
    long long int n;
    long long int e;
    bool operator<(const Level& t)const{
        return e<t.e;
    }
}lev[MAXN];

int main()
{
    int T; scanf("%d", &T);
    long long int l;
    long long int maxe, sum, ans;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        maxe=0;
        sum=0;
        scanf("%lld",&l);
        for(int i=0;i<l;++i){
            scanf("%lld %lld",&lev[i].n, &lev[i].e);
            if(lev[i].e>maxe)
                maxe=lev[i].e;
        }
        maxe++;
        sort(lev,lev+l);
        for(int i=0;i<l;++i){
            sum-=lev[i].e*lev[i].n;
            sum = sum<=0? 0:sum;
            sum+=lev[i].n;
        }
        ans = sum>maxe?sum:maxe;
        printf("%lld\n",ans);
    }


}