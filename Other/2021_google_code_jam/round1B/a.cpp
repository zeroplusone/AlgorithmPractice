// Dead Body
#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define PR pair<int,int>

#define pb push_back
#define mp make_pair

#define TICK 12*1e-10
#define ROUND 43200

int main()
{
    int T; scanf("%d", &T);
    LL A, B, C, X, Y, ans;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        cin>>A>>B>>C;
        A*=TICK;
        B*=TICK;
        C*=TICK;
        X=B-A;
        Y=C-B;

        ans=0;
        if(X%11==0) {
            if(Y%708==0) { // h-m-s
                ans=A;
            } else if(Y%719==0) { // m-h-s
                ans=B;
            }
        }else if(X%708==0) {
            if(Y%11==0) { // s-m-h
                ans=C;
            } else if(Y%719==0) { // m-s-h
                ans=C;
            }
        }else if(X%719==0) {
            if(Y%11==0) { // s-h-m
                ans=B;
            } else if(Y%708==0) { // h-s-m
                ans=A;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
