class Solution {
public:
    int index;
    vector<vector<int>> ans;
        
    void DFS(int v1, int v2, vector<int>& dfn, vector<int>& low, vector<vector<int>>& adj) {
        dfn[v2]=index;
        low[v2]=index;
        index++;

        for(auto v3: adj[v2]) {
            if(dfn[v3]!=-1) {
                if(v3!=v1) {
                    low[v2] = min(low[v2], dfn[v3]);
                }
            } else {
                DFS(v2, v3, dfn, low, adj);
                low[v2] = min(low[v2], low[v3]);
                
                if(low[v3]>dfn[v2]) {
                    ans.push_back(vector<int>{v2, v3});
                }
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> dfn(n, -1);
        vector<int> low(n, n);
        vector<vector<int>> adj(n, vector<int>(0));
        
        for(auto connection: connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        index=0;
        for(int i=0;i<n;++i) {
            if(dfn[i]==-1) {
                DFS(i, i, dfn, low, adj);                
            }
        }
        return ans;
    }
};
