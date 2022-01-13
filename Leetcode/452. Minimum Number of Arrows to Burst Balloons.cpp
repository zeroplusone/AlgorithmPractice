class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        int end=points[0][1];
        int ans=1;
        for(int i=1;i<points.size();++i) {
            if(points[i][1]<end) {
                end=points[i][1];
            } else {
                if(points[i][0]>end) {
                    ans++;
                    end=points[i][1];
                }
            }
        }
        return ans;
    }
};
