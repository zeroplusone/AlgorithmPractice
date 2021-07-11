#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define PR pair<int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

int main()
{
    int T; scanf("%d", &T);
    vector<vector<int>> g(3, vector<int>(3));
    int ans;
    for(int tt = 1; tt <= T; tt++){
        cin>>g[0][0]>>g[0][1]>>g[0][2];
        cin>>g[1][0]>>g[1][2];
        cin>>g[2][0]>>g[2][1]>>g[2][2];
        ans=0;
        if(g[0][1]-g[0][0]==g[0][2]-g[0][1]) {
            ans++;
        }
        if(g[2][1]-g[2][0]==g[2][2]-g[2][1]) {
            ans++;
        }
        if(g[1][0]-g[0][0]==g[2][0]-g[1][0]) {
            ans++;
        }
        if(g[1][2]-g[0][2]==g[2][2]-g[1][2]) {
            ans++;
        }
        unordered_map<int, int> cnt;
        if((g[0][0]+g[2][2])%2==0) {
            cnt[(g[0][0]+g[2][2])/2]++;
        }
        if((g[0][2]+g[2][0])%2==0) {
            cnt[(g[0][2]+g[2][0])/2]++;
        }
        if((g[0][1]+g[2][1])%2==0) {
            cnt[(g[0][1]+g[2][1])/2]++;
        }
        if((g[1][0]+g[1][2])%2==0) {
            cnt[(g[1][0]+g[1][2])/2]++;
        }

        int maxv=0;
        for(auto c:cnt) {
            maxv=max(maxv, c.second);
        }
        ans+=maxv;
        printf("Case #%d: ", tt);
        printf("%d\n", ans);
    }

    return 0;
}
