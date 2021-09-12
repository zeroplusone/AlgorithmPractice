class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long int ans=0;
        unordered_map<double, long long int> cnt;
        for(int i=0;i<rectangles.size();++i) {
            cnt[rectangles[i][0]/(double)rectangles[i][1]]++;
        }
        
        for(auto c: cnt) {
            ans+=c.second*(c.second-1)/2;
        }
        return ans;
    }
};
