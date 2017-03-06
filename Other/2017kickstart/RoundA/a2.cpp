#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;

typedef long long LL;
#define MOD 1000000007

#define PR pair<int,int>
#define mp make_pair
#define x first
#define y second
 
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

int main()
{
    int casenum;
    int ans;
    int R,C,n;
    scanf("%d",&casenum);

    for(int cc=1;cc<=casenum;++cc)
    {
        printf("Case #%d: ",cc);
        scanf("%d%d",&R,&C);
        n=min(R,C)-1;
        ans=0;
        // for(int i=1;i<minRC;++i){
        //     ans+=(R-i)*(C-i)%MOD;
        // }
        // ans+=R*C%MOD*n%MOD*(n+1)%MOD/2;
        // ans-=(R+C)%MOD*n%MOD*(n+1)%MOD*(2*n+1)%MOD/6;
        // ans+=n*(n+1)%MOD*n%MOD*(n+1)%MOD/2;
        // ans%=MOD;
        //ans+=(R-1)*(C-1)%MOD;
        //----------
        // ans+=R*C%MOD*n%MOD*(n+1)%MOD/2%MOD;
        // ans-=(R+C)%MOD*n%MOD*(n+1)%MOD*(2*n+1)%MOD/6%MOD;
        // ans+=n*(n+1)%MOD*n%MOD*(n+1)%MOD/4%MOD;
        //---------
        ans=Add(ans,Div(Mult(Mult(Mult(R,C),n),n+1),2));
        ans=Sub(ans,Div(Mult(Mult(Mult(Add(R,C),n),n+1),2*n+1),6));
        ans=Add(ans,Div(Mult(Mult(n,n+1),Mult(n,n+1)),4));
        //ans-=(C-1)*(R-1)%MOD;
        // ans-=n*R*C;
        // ans+=(R+C)*n*(n+1)/2%MOD;
        // ans-=n*(n+1)*(2*n+1)/6%MOD;
        
        printf("%d\n",ans);
    }
    return 0;
}
