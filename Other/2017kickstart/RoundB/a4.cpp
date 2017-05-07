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

PR GCD(int a,int b)
{
    if (!b)
        return(mp(1,0));
    PR p=GCD(b,a%b);
    return(mp(p.y,p.x-p.y*(a/b)));
}

int Add(int a,int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
    return(a);
}

int Sub(int a,int b)
{
    a-=b;
    if (a<0)
        a+=MOD;
    return(a);
}

int Mult(int a,int b)
{
    return((LL)a*b%MOD);
}

int Div(int a,int b)
{
    b=GCD(b,MOD).x;
    if (b<0)
        b+=MOD;
    return(Mult(a,b));
}

int power30=Mult((int)pow(2,29),2);
int power(int a, int b){
    if(b<30){
        return (int)pow(a,b);
    }else{
        int ret=1;
        for(int i=0;i<b/30;++i){
            ret=Mult(ret,power30);
        }
        ret=Mult(ret,(int)pow(2,b%30));
        return ret;
    }
}

int power2(int a, int b){
    if(b==0){
        return 1;
    }else if (b==1){
        return a;
    }else{
        if(b%2==1){
            return Mult(a,Mult(power2(a,b/2),power2(a,b/2)));
        }else{
            return Mult(power2(a,b/2),power2(a,b/2));
        }
    }
}

int main()
{
    int T; scanf("%d", &T);
    int n;
    int l,r;
    int ans, diff;
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
            for(int j=i;j<n;++j){
                ans=Add(ans,Mult(k[j]-k[i],(int)pow(2,j-i-1)));
                //Debug(ans)
            }
        }
        printf("%d\n",ans);
    }


}