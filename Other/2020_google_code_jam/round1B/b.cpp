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
    int T; scanf("%d", &T);
    long long int A, B;
    cin>>A>>B;
    for(int tt = 1; tt <= T; tt++){

        long long int x=0;
        long long int y=0;
        long long int l=-1000000000, r=1000000000;
        long long int d=-1000000000, u=1000000000;
        long long int test;

        string ansl, ansr, ansd, ansu, ans;
        while(true) {
            cout<<x<<" "<<y<<endl;
            cin>>ans;
            if(ans=="CENTER") {
                break;
            }

            test=x+A>1000000000?1000000000:x+A;
            cout<<test<<" "<<y<<endl;
            cin>>ansr;
            test=x-A<-1000000000?-1000000000:x-A;
            cout<<test<<" "<<y<<endl;
            cin>>ansl;
            test=y+A>1000000000?1000000000:y+A;
            cout<<x<<" "<<test<<endl;
            cin>>ansu;
            test=y-A<-1000000000?-1000000000:y-A;
            cout<<x<<" "<<test<<endl;
            cin>>ansd;
            if(ansr=="HIT" && ansl=="MISS"){
                l=x;
                x=(x+r)/2;
            }else if (ansr=="MISS" && ansl=="HIT"){
                r=x;
                x=(x+l)/2;
            }
            if(ansu=="HIT" && ansd=="MISS"){
                d=y;
                y=(y+u)/2;
            }else if (ansu=="MISS" && ansd=="HIT"){
                u=y;
                y=(y+d)/2;
            }
        }
        
    }
    return 0;
}