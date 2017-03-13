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



void backtracking(int now, int n){
    if(now==n){
        double sum=1;
        for (int i = 0; i < n; ++i)
        {
            sum*=1-pmul[i];
        }
        if(sum-ans>EPS){
            ans=sum;
        }
        return;
    }
    for (int i = 0; i < 2*n; ++i)
    {
        if(!v[i]){
            v[i]=true;
            for(int j=i+1;j<2*n;++j){
                if(!v[j]){
                    v[j]=true;
                    pmul[now]=p[i]*p[j];
                    backtracking(now+1,n);
                    v[j]=false;
                }
            }
            v[i]=false;
        }
    }
}

int main()
{
    int n;
    int T; scanf("%d", &T);
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        ans=0;
        Fill(v,false);
        scanf("%d",&n);
        for (int i = 0; i < 2*n; ++i)
        {
            scanf("%lf",&p[i]);
        }
        backtracking(0,n);

        printf("%lf\n",ans);
    }


}