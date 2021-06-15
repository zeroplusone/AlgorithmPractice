class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(), matchsticks.end());
        reverse(matchsticks.begin(), matchsticks.end());

        long long int edge=0;
        for(int i=0;i<matchsticks.size();++i) {
            edge+=matchsticks[i];
        }
        edge/=4;
        for(int i=0;i<matchsticks.size();++i) {
            if(matchsticks[i]>edge) {
                return false;
            }
        }
        vector<int> edges(4, edge);
        return solve(0, edges, matchsticks);
    }
    
    bool solve(int now, vector<int>& edges,vector<int>& matchsticks) {
        if(now==matchsticks.size()) {
            for(int i=0;i<edges.size();++i) {
                if(edges[i]!=0) {
                    return false;
                }
            }
            return true;
        } 

        for(int i=0;i<edges.size();++i) {
            if(edges[i]-matchsticks[now]>=0) {
                edges[i]-=matchsticks[now];
                if(solve(now+1, edges, matchsticks)) {
                    return true;
                }
                edges[i]+=matchsticks[now];
            }
        }
        return false;
    }
};
