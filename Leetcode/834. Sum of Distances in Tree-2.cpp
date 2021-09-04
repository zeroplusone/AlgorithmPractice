class Solution {
public:

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n, 0);
        vector<int> cnt(n, 0);
        unordered_map<int, vector<int>> graph;
        for(int i=0;i<edges.size();++i) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        buildTree(0, -1, graph, cnt, ans);
        solve(0, -1, graph, cnt, ans, n);
        return ans;
    }
    
    void buildTree(int now, int parent, unordered_map<int, vector<int>>& graph, vector<int>& cnt, vector<int>& ans) {
        cnt[now]++;
        for(int i=0;i<graph[now].size();++i) {
            if(graph[now][i]!=parent) {
                buildTree(graph[now][i], now, graph, cnt, ans);
                cnt[now]+=cnt[graph[now][i]];
                ans[now]+=ans[graph[now][i]]+cnt[graph[now][i]];
            }
        }
    }
    
    void solve(int now, int parent, unordered_map<int, vector<int>>& graph, vector<int>& cnt, vector<int>& ans, int& n) {
        for(int i=0;i<graph[now].size();++i) {
            if(graph[now][i]!=parent) {
                ans[graph[now][i]]=ans[now]-cnt[graph[now][i]]+n-cnt[graph[now][i]];        
                solve(graph[now][i], now, graph, cnt, ans, n);
            }
        }
    }
    
       
};
