class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n=graph.size();
        vector<bool> v(n, false);
        vector<int> route(0);
        DFS(0, v, graph, route, ans);
        return ans;
    }
    
    void DFS(int now, vector<bool>& v, vector<vector<int>>& g, vector<int>& r, vector<vector<int>>& ans) {
        if(now==g.size()-1) {
            r.push_back(now);
            ans.push_back(r);
            r.pop_back();
            return;
        }
        
        if(!v[now]) {
            v[now]=true;
            r.push_back(now);
            for(int i=0;i<g[now].size();++i) {
                DFS(g[now][i], v, g, r, ans);
            }
            r.pop_back();
            v[now]=false;
        }
    }
};
