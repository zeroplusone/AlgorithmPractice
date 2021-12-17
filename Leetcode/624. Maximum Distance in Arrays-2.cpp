class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minv=arrays[0][0];
        int maxv=arrays[0][arrays[0].size()-1];
        int ans=0;
        for(int i=1;i<arrays.size();++i) {
            ans=max(ans, abs(minv-arrays[i][arrays[i].size()-1]));
            ans=max(ans, abs(maxv-arrays[i][0]));
            
            minv=min(minv, arrays[i][0]);
            maxv=max(maxv, arrays[i][arrays[i].size()-1]);
        }
        return ans;
    }
};
