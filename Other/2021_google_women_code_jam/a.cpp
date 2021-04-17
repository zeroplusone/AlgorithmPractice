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
    int N, s;
    for (int tt = 1; tt <= T; tt++) {
        printf("Case #%d: ", tt);
        cin>>N;
        map<int, int> sizeMaps;
        for (int i=0;i<N;++i) {
            scanf("%d", &s);
            sizeMaps[s]++;
        }
        int cnt=1;
        int ans=0;
        for(auto sizeMap: sizeMaps) {
            ans+=cnt*sizeMap.second;
            cnt++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
