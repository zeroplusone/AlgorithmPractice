class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> ans;
        int minh=0;
        for(int i=heights.size()-1;i>=0;--i) {
            if(heights[i]>minh) {
                ans.push_back(i);
                minh=heights[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
