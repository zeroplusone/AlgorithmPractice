class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        map<int, vector<pair<int, int>>> elem;
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                int val=matrix[i][j];
                if(elem.count(val)==0) {
                    elem[val]=vector<pair<int, int>>{make_pair(i, j)};
                } else {
                    elem[val].push_back(make_pair(i, j));
                }
            }
        }
        

        vector<int> rank(m+n, 0);
    
        vector<vector<int>> ans(m, vector<int>(n, 1));
        for(auto& it: elem) {
            vector<int> p(m+n);
            for(int i=0;i<m+n;++i) {
                p[i]=i;
            }
            vector<int> rank2=rank;
            for(int i=0;i<it.second.size();++i) {
                int x=it.second[i].first;
                int y=it.second[i].second;

                int xp=findp(x, p);
                int yp=findp(m+y, p);
                p[yp]=xp;
                rank2[xp]=max(rank2[xp], rank2[yp]);
            }
            for(int i=0;i<it.second.size();++i) {
                int x=it.second[i].first;
                int y=it.second[i].second;
                
                ans[x][y]=rank2[findp(x, p)]+1;
                rank[x]=ans[x][y];
                rank[m+y]=ans[x][y];
            }
        }
        return ans;
    }
    
    int findp(int now, vector<int>& p) {
        return p[now]!=now?findp(p[now], p):now;
    }
};
