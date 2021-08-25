class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> p(n, -1);
            
        if(edges.size()!=n-1) {
            return false;
        }
        
        for(int i=0;i<edges.size();++i) {
            int x=findp(edges[i][0], p);
            int y=findp(edges[i][1], p);
            
            if(x==y) {
                return false;
            }
            
            p[x]=y;
        }
        return true;
    }
    
    int findp(int now, vector<int>& p) {
        if(p[now]==-1) {
            return now;
        } else {
            return findp(p[now], p);
        }
    }
    

};
