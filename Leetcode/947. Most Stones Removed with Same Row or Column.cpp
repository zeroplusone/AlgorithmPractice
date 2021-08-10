class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int edge=1e4+2;
        unordered_map<int, int> p;
        for(int i=0;i<n;++i) {
            int x=stones[i][0];
            int y=stones[i][1]+edge;
            if(p.count(x)==0) {
                p[x]=x;
            }
            if(p.count(y)==0) {
                p[y]=y;
            }
            int xp=findp(x, p);
            int yp=findp(y, p);
            p[yp]=xp;
        }
        
        int cnt=0;
        for(auto& it: p){
            if(it.first==it.second) {
                
                cnt++;
            }
        }
        return n-cnt;
    }
    
    int findp(int now, unordered_map<int, int>& p) {
        return now==p[now]?now:findp(p[now], p);
    }
};
