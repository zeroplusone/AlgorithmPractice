#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define PR pair<int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second
void DFS(int x, int y, vector<vector<char>>& g, vector<vector<bool>>& v, int& ans) {
    if(v[x][y] || g[x][y]=='.' || g[x][y]=='#') {
        return;
    }
    v[x][y]=true;
    int rend=y;
    while(rend<g[0].size() && g[x][rend]!='#') {
        rend++;
    }

    int lend=y;
    while(lend>=0 && g[x][lend]!='#') {
        lend--;
    }

    int mirrory=y<=(rend+lend)/2?rend-(y-lend):lend+(rend-y);
    ans+=g[x][mirrory]=='.'?1:0;
    g[x][mirrory]=g[x][y];
    DFS(x, mirrory, g, v, ans);
    int dend=x;
    while(dend<g.size() && g[dend][y]!='#') {
        dend++;
    }
    int uend=x;
    while(uend>=0 && g[uend][y]!='#') {
        uend--;
    }

    int mirrorx=x<=(uend+dend)/2?dend-(x-uend):uend+(dend-x);
    ans+=g[mirrorx][y]=='.'?1:0;
    g[mirrorx][y]=g[x][y];
    DFS(mirrorx, y, g, v, ans);

}

int main()
{
    int T; scanf("%d", &T);
    int N, M;
    for(int tt = 1; tt <= T; tt++){
        cin>>N>>M;
        vector<vector<char>> g(N, vector<char>(M));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin>>g[i][j];
            }
        }

        int ans=0;
        vector<vector<bool>> v(N, vector<bool>(M, false));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                DFS(i, j, g, v, ans);
            }
        }
        printf("Case #%d: %d\n", tt, ans);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cout<<g[i][j];
            }
            cout<<endl;
        }

    }

    return 0;

}
