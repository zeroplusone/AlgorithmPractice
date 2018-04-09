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

#define MAX 110
long long int dp[MAX][MAX];
long long int c(int a,int b)
{
    if(a>=0 && b>=0 && dp[a][b])
        return dp[a][b];
    else if(a==b)
        dp[a][b]=1;
    else if(a<b)
        dp[a][b]=0;
    else if(a<=1)
        dp[a][b]=1;
    else if(b==1)
        dp[a][b]=a;
    else if(b==0)
        dp[a][b]=1;
    else{
        int tmp=b;
        if(b*2>a)
            tmp=a-b;
        dp[a][b]=c(a-1,tmp)+c(a-1,tmp-1);
    }
    return dp[a][b];
}

double ans;

int main()
{
    int T; scanf("%d", &T);
    int n;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        scanf("%d",&n);
        ans=1;
        solve(n);
        printf("%.6lf\n",ans);
    }


}