#include <bits/stdc++.h>
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

string ans;

void backTrack(long long int nowx, long long int nowy, long long int X, long long int Y, string path) {
    //cout<<ans<<" "<<nowx<<" "<<nowy<<" "<<X<<" "<<Y<<" "<<path<<endl;
    if(nowx==X && nowy==Y) {
        if(ans=="" || ans.length()>path.length()) {
            ans=path;
        }
        return;
    }

    long long int step=pow(2, path.length());

    if(nowx>1000000000 || nowx<-1000000000 || nowy >1000000000 || nowy<-1000000000 || step>=200 || (ans!="" && path.length()>=ans.length())){
        return;
    }

    backTrack(nowx+step, nowy, X, Y, path+"E");
    backTrack(nowx-step, nowy, X, Y, path+"W");
    backTrack(nowx, nowy+step, X, Y, path+"N");
    backTrack(nowx, nowy-step, X, Y, path+"S");

}

int main()
{
    int T; scanf("%d", &T);
    long long int X, Y;

    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        scanf("%lld%lld",&X, &Y);
        ans="";
        backTrack(0, 0, X, Y, "");
        if(ans=="") {
            cout<<"IMPOSSIBLE"<<endl;
        } else {
            cout<<ans<<endl;
        }
    }

    return 0;
}