class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, int> p;
        int base=1e4+1;
        for(int i=0;i<stones.size();++i) {
            int x=stones[i][0];
            int y=base+stones[i][1];
            
            int px=findp(x, p);
            int py=findp(y, p);
            p[py]=px;
        }
        
        unordered_map<int, int> stoneCnt;
        for(int i=0;i<stones.size();++i) {
            int px=findp(stones[i][0], p);
            stoneCnt[px]++;
        }
        
        return stones.size()-stoneCnt.size();
    }
    
    int findp(int now, unordered_map<int, int>& p) {
        if(p.count(now)==0 || p[now]==now) {
            return now;
        } else {
            p[now]=findp(p[now], p);
            return p[now];
        }
    }
};
