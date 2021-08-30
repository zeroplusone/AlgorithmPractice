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
    cin>>T;
    for (int tt = 1; tt <= T; tt++) {
        string S;
        int K;
        cin>>S>>K;
        string p;
        vector<unordered_map<char, int>> mapping(26, unordered_map<char, int>{});
        vector<vector<char>> graph(26, vector<char>(0));
        for (int i = 0; i < K; ++i) {
            cin>>p;
            int from=p[1]-'A';
            graph[from].push_back(p[0]);
        }

        for (int i = 0; i < 26; ++i) {
            queue<int> que;
            que.push(i);
            mapping[i]['A'+i]=0;
            int step=1;
            while(!que.empty()) {
                int len=que.size();
                for (int j = 0; j < len; ++j) {
                    int now=que.front(); que.pop();
                    for (int k = 0; k < graph[now].size(); ++k) {
                        if(mapping[i].count(graph[now][k])==0) {
                            mapping[i][graph[now][k]]=step;
                            que.push(graph[now][k]-'A');
                        }
                    }
                }
                step++;
            }
        }

//        for (int i = 0; i < 26; ++i) {
//            cout<<"Start from "<<(char)('A'+i)<<endl;
//            for(auto it: mapping[i]) {
//                cout<<it.first<<" "<<it.second<<endl;
//            }
//        }
        int ans=1e9;
        for (int i = 0; i < 26; ++i) {
            int cnt=0;
            int j=0;
            for (; j < S.length(); ++j) {
                if(mapping[i].count(S[j])!=0) {
                    cnt+=mapping[i][S[j]];
                } else {
                    break;
                }
            }
            if(j==S.length()) {
                ans=min(ans, cnt);
            }
        }

        ans=ans==1e9?-1:ans;
        printf("Case #%d: ", tt);
        printf("%d\n", ans);
    }
    return 0;
}
