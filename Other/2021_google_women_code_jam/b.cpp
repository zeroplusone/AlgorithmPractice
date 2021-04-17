#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define PR pair<int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

int main() {
    int T;
    scanf("%d", &T);
    int N;
    for (int tt = 1; tt <= T; tt++) {
        printf("Case #%d: ", tt);
        cin>>N;
        vector<int> L(N);
        for (int i=0;i<N;++i) {
            cin>>L[i];
        }
        string ans="A";
        char last='A';
        for(int i=0;i<N;++i) {
            if(i%2==0) {
                for(int j=1;j<L[i];++j) {
                    ans+=last+j;
                }
                if(i==N-1) {
                    ans+=last+L[i];
                }else if(L[i+1]>L[i]){
                    last='A' + L[i + 1];
                    ans += last;
                } else {
                    ans+=last+L[i];
                    last='A'+L[i+1];
                }
            } else {
                for(int j=1;j<L[i];++j) {
                    ans+=last-j;
                }
                ans+='A';
                last='A';
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
