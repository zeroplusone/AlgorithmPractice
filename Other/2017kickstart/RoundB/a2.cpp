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

int a_b_Mod_c(int a,int b,int c){ // 前提 abc 都是正數
    int digit[32];
    int i=0;
    int result=1;
    while(b){ 
        digit[i++]=b%2; b>>=1; 
    } // 把 b 化成 2 進制 
    for(int k=i-1; k>=0; k--){ // 計算(a^b) mod c
        result=Mult(result,result);
        if(digit[k]==1) result=Mult(result,a); 
    }
    return result; 
}

int main()
{
    int T; scanf("%d", &T);
    int n;
    int l,r;
    int ans, diff, time;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        scanf("%d",&n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d",&k[i]);
        }
        ans=0;
        for (int i = 0; i < n-1; ++i)
        {
            diff=k[i+1]-k[i];
            time=0;
            for(int j=1;j<n;++j){
                l=i-j+1<0?0:i-j+1;
                r=i+j>n-1?n-1-j:i;
                //if(r>=l){
                    time+=Mult(a_b_Mod_c(2,j-1,MOD),(r-l+1));
                    // Debug(i)
                    // Debug(j)
                    // Debug(diff)
                    // Debug(r)
                    // Debug(l)
                    // Debug(r-l+1)
                // }else{
                    // break;
                // }
            }
            ans=Add(ans,Mult(diff,time));      
            Debug(ans)
        }
        //Div(ans,2);
        printf("%d\n",ans);
    }


}