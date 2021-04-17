#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define PR pair<int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second
int M, N;
int solve(int p1, int p2, vector<vector<int>>& dp, vector<bool>& v) {
    if(dp[p1][p2]!=1e4) {
        return dp[p1][p2];
    } else {
        v[p1]=true;
        v[p2]=true;
        for(int i=1;i<=M;++i) {
            if(!v[i]) {
                int s1=solve(i, p1, dp, v);
                int s2=solve(i, p2, dp, v);
                int ret = s1+s2+1>1e4?1e4:s1+s2+1;
                dp[p1][p2] = min(dp[p1][p2], ret);
                dp[p2][p1]=dp[p1][p2];
            }
        }
        v[p1]=false;
        v[p2]=false;
        return dp[p1][p2];
    }
}

int main() {
    int T;
    scanf("%d", &T);
    int P;
    int p1, p2;
    string s;
    for (int tt = 1; tt <= T; tt++) {
        printf("Case #%d:", tt);
        cin>>M>>N>>P;
        vector<vector<int>> dp(M+N+1, vector<int>(M+N+1, 1e4));
        for(int i=1;i<=M+N;++i) {
            cin>>s;
            for(int j=0;j<s.length();++j) {
                if(s[j]=='Y') {
                    dp[i][j+1]=0;
                }
            }
        }
        for(int i=0;i<P;++i) {
            cin>>p1>>p2;
            vector<bool> v(M+N+1, false);
            int ans = solve(p1, p2, dp, v);
            if(ans==1e4) {
                cout<<" -1";
            } else {
                cout<<" "<<ans;
            }
        }
        cout<<endl;
    }
    return 0;
}
