class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> bricks;
        
        int ans=0;
        for(int i=0;i<wall.size();++i) {
            int cnt=0;
            for(int j=0;j<wall[i].size()-1;++j) {
                cnt+=wall[i][j];
                bricks[cnt]++;
                ans=max(ans, bricks[cnt]);
            }
        }
        return wall.size()-ans;
    }
};
