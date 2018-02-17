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

#define MAXN 150
int d[MAXN];

int main()
{
    int T; scanf("%d", &T);
    int k, ans, k2;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        Fill(d,0);
        ans=0;
        scanf("%d",&k);
        for(int i=0;i<k;++i){
            scanf("%d",&d[i]);
        }
        sort(d,d+k);
        k2=(int)k/2;
        for(int i=0;i<k2;++i){
            ans+=(d[i*2]-i)*(d[i*2]-i);
            ans+=(d[i*2+1]-i)*(d[i*2+1]-i);
        }

        if(k%2==1){
            ans+=(d[k-1]-k2)*(d[k-1]-k2);
        }
        printf("%d\n",ans);
    }
    return 0;

}