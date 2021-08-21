class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        auto cmp = [](vector<int> p1, vector<int> p2) {
            return sqrt(p1[0]*p1[0]+p1[1]*p1[1])<sqrt(p2[0]*p2[0]+p2[1]*p2[1]);
        };
        nth_element(points.begin(), points.begin()+k, points.end(), cmp);

        return vector<vector<int>>(points.begin(), points.begin()+k);
    }
};
