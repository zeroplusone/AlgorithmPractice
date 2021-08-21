class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        pair<double, vector<int>> p;
        
        auto cmp = [](pair<double, vector<int>> p1, pair<double, vector<int>> p2) {
            return p1.first<p2.first;
        };
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, decltype(cmp)> pq(cmp);
        
        for(int i=0;i<points.size();++i) {
            double dis=sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            if(pq.size()<k) {
                pq.push(make_pair(dis, points[i]));
            } else if(pq.top().first>dis){
                pq.pop();
                pq.push(make_pair(dis, points[i]));
            }
        }
                        
        vector<vector<int>> ans(k);
        for(int i=0;i<k;++i) {
            ans[i]=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};
