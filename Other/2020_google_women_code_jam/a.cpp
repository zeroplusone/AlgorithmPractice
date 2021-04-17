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

    string s;
    for (int tt = 1; tt <= T; tt++) {
        int cI=0;
        int ci=0;
        int ans=0;
        cin>>s;
        for(auto c:s) {
            if(c=='I') {
                cI++;
            }else if(c=='i') {
                ci++;
            } else if(c=='O') {
                if(cI>0) {
                    ans++;
                    cI--;
                } else {
                    ci--;
                }
            } else if(c=='o') {
                if(ci>0) {
                    ci--;
                } else {
                    cI--;
                }
            }
        }
        printf("Case #%d: ", tt);
        printf("%d\n", ans);
    }
    return 0;
}
