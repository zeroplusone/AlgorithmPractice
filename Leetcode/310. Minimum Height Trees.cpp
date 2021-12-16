class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) {
            return vector<int>{0}; 
        }
        unordered_map<int, set<int>> e;
        for(int i=0;i<edges.size();++i) {
            e[edges[i][0]].insert(edges[i][1]);
            e[edges[i][1]].insert(edges[i][0]);
        }
        vector<int> leaves;
        
        for(int i=0;i<n;++i) {
            if(e[i].size()==1) {
                leaves.push_back(i);
            }
        }
        
        int remaining=n;
        while(remaining>2) {
            vector<int> newLeaves;
            remaining-=leaves.size();
            
            for(int i=0;i<leaves.size();++i) {
                for(auto neighbor: e[leaves[i]]) {
                    e[neighbor].erase(leaves[i]);
                    if(e[neighbor].size()==1) {
                        newLeaves.push_back(neighbor);
                    }
                }
            }
            leaves=newLeaves;
        }
        return leaves;
    }
};
