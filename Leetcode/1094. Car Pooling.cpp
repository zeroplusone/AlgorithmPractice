class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> pairs;
        for(int i=0;i<trips.size();++i) {
            pairs.push_back(make_pair(trips[i][1], trips[i][0]));
            pairs.push_back(make_pair(trips[i][2], -trips[i][0]));
        }
        sort(pairs.begin(), pairs.end());
        
        int now=0;
        for(int i=0;i<pairs.size();++i) {
            if(now+pairs[i].second>capacity) {
                return false;
            }
            now+=pairs[i].second;
        }
        return true;
    }
};
