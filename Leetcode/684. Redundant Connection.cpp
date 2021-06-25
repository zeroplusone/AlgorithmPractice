class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> p(n+1);
        vector<int> rank(n+1, 0);
        for(int i=1;i<=n;++i) {
            p[i]=i;
        }

        vector<int> ans;
        for(int i=0;i<edges.size();++i) {
            int x=findSet(edges[i][0], p);
            int y=findSet(edges[i][1], p);
            if(x==y) {
                ans=edges[i];
            } else {
                unite(edges[i][0], edges[i][1], p, rank);
            }
        }
        return ans;
    }
    
    void unite(int x, int y, vector<int>& p, vector<int>& rank) {
        int xp = findSet(x, p);
        int yp = findSet(y, p);
        
        if(rank[xp]>rank[yp]) {
            p[yp]=xp;
        } else {
            p[xp]=yp;
            if(rank[xp]==rank[yp]) {
                rank[yp]++;
            }
        }
    }
    
    int findSet(int x, vector<int>& p) {
        if(p[x]!=x) {
            p[x]=findSet(p[x], p);
        } 
        
        return p[x];
    }
};
