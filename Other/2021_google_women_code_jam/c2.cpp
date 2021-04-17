#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define PR pair<int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second
int M, N;

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

        bool refresh=false;
        do {
            refresh=false;
            for (int i = 1; i <= M; ++i) {
                for (int j = 1; j <= M + N; ++j) {
                    for (int k = 1; k <= M + N; ++k) {
                        if (i!=j&&j!=k&&i!=k&&dp[i][j] != 1e4 && dp[i][k] != 1e4) {
                            if(dp[i][j] + dp[i][k] + 1< dp[j][k]) {
                                dp[j][k] = dp[i][j] + dp[i][k] + 1;
                                dp[k][j] = dp[j][k];
                                refresh=true;

                            }
                        }
                    }
                }
            }
        } while(refresh);

        for(int i=0;i<P;++i) {
            cin>>p1>>p2;
            if(dp[p1][p2]==1e4) {
                cout<<" -1";
            } else {
                cout<<" "<<dp[p1][p2];
            }
        }
        cout<<endl;
    }
}
