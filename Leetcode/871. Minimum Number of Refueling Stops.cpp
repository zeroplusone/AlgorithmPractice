class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int ans=0;
        int fuel=startFuel;
        stations.push_back(vector<int>{target, 0});
        for(int i=0;i<stations.size();++i) {
            if(fuel>=target) {
                break;
            } else {
                while(!pq.empty() && fuel<stations[i][0]) {
                    fuel+=pq.top();
                    ans++;
                    pq.pop();
                }
                if(fuel<stations[i][0]) {
                    return -1;
                } else {
                    pq.push(stations[i][1]);
                }
            }
        }
        return ans;
    }
};
