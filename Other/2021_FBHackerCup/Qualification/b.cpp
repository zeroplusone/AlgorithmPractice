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
    for (int tt = 1; tt <= T; tt++) {
        int N;
        cin>>N;
        vector<int> rowX(N, 0);
        vector<int> rowO(N, 0);
        vector<int> colX(N, 0);
        vector<int> colO(N, 0);
        string in;
        vector<vector<char>> graph(N, vector<char>(N));
        for (int i = 0; i < N; ++i) {
            cin>>in;
            for (int j = 0; j < in.length(); ++j) {
                graph[i][j]=in[j];
                if(in[j]=='O') {
                    rowO[i]++;
                    colO[j]++;
                } else if(in[j]=='X') {
                    rowX[i]++;
                    colX[j]++;
                }
            }
        }

        int ans=1e9, cnt=0;
        for (int i = 0; i <N; ++i) {
            // row
            if(rowO[i]==0) {
                int fill=N-rowX[i];
                if(ans>fill) {
                    ans=fill;
                    cnt=1;
                } else if(ans==fill) {
                    cnt++;
                }
            }
            //col
            if(colO[i]==0) {
                int fill=N-colX[i];
                if(ans>fill) {
                    ans=fill;
                    cnt=1;
                } else if(ans==fill) {
                    cnt++;
                }
            }
        }

        if(ans==1) {
            cnt=0;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if(graph[i][j]=='.') {
                        if(rowX[i]==N-1 || colX[j]==N-1) {
                            cnt++;
                        }
                    }
                }
            }
        }
        printf("Case #%d: ", tt);
        if(ans==1e9) {
            printf("Impossible\n");
        } else {
            printf("%d %d\n", ans, cnt);
        }
    }
    return 0;
}
