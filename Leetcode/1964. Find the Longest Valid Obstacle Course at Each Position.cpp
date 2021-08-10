class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int> ans(n);
        vector<int> vec=vector<int>(0);
        for(int i=0;i<n;++i) {
            if(vec.size()==0 || vec.back()<=obstacles[i]) {
                vec.push_back(obstacles[i]);
                ans[i]=vec.size();
            } else {
                auto index=upper_bound(vec.begin(), vec.end(), obstacles[i]);
                *index=obstacles[i];
                ans[i]=index-vec.begin()+1;
            }
        }
        return ans;
    }
};
