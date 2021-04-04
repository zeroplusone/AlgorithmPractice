class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> calculation;
        unordered_set<int> set;
        for(auto log:logs) {
            calculation[log[0]].insert(log[1]);
        }
        vector<int> ans(k);
        for(auto cal:calculation) {
            ans[cal.second.size()-1]++;
        }
        return ans;
    }
};
