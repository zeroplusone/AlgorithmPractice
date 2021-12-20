class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minv=1e9;
        vector<vector<int>> ans;
        for(int i=0;i<arr.size()-1;++i) {
            int diff=arr[i+1]-arr[i];
            if(minv>=diff) {
                if(minv>diff) {
                    ans.clear();    
                }
                ans.push_back(vector<int>{arr[i], arr[i+1]});
                minv=diff;
            }
        }
        return ans;
    }
};
