class Solution {
public:

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n, -1);
        vector<int> cnt(n, 0);
        unordered_map<int, vector<int>> graph;
        for(int i=0;i<edges.size();++i) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        ans[0]=buildTree(0, -1, graph, cnt);
        solve(0, -1, graph, cnt, ans, n);
        return ans;
    }
    
    int buildTree(int now, int parent, unordered_map<int, vector<int>>& graph, vector<int>& cnt) {
        int nodeNum=1;
        int subTreeSum=0;
        for(int i=0;i<graph[now].size();++i) {
            if(graph[now][i]!=parent) {
                subTreeSum+=buildTree(graph[now][i], now, graph, cnt);
                subTreeSum+=cnt[graph[now][i]];
                nodeNum+=cnt[graph[now][i]];
            }
        }
        cnt[now]=nodeNum;
        return subTreeSum;
    }
    
    void solve(int now, int parent, unordered_map<int, vector<int>>& graph, vector<int>& cnt, vector<int>& ans, int& n) {
        if(ans[now]==-1) {
            ans[now]=ans[parent]-cnt[now]+n-cnt[now];    
        }
        for(int i=0;i<graph[now].size();++i) {
            if(graph[now][i]!=parent) {
                solve(graph[now][i], now, graph, cnt, ans, n);
            }
        }
    }
    
       
};
