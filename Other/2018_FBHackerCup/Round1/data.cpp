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

int main()
{
    // cout<<"1"<<endl<<"1000"<<endl;
    // int i,j;
    // ForN(i,3){
    //     ForN(j,1000){
    //         cout<<".";
    //     }
    //     cout<<endl;
    // }
    LL ans;
    ans =1;
    int i;
    ForN(i,499){
        ans=(ans*2)%1000000007;
    }    
    cout<<ans<<endl;
    return 0;

}
