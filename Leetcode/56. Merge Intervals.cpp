class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int st=intervals[0][0];
        int en=intervals[0][1];
        
        vector<vector<int>> ans;
        for(int i=1;i<intervals.size();++i) {
            if(intervals[i][0]>en) {
                ans.push_back(vector<int>{st, en});
                st=intervals[i][0];
                en=intervals[i][1];
            } else {
                en=max(en, intervals[i][1]);
            }
        }
        ans.push_back(vector<int>{st, en});
        return ans;
    }
};
