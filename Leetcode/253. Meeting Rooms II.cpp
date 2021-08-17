class Solution {
public:
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);
        int ans=1;
        
        for(int i=1;i<intervals.size();++i) {
            if(!pq.empty() && pq.top()>intervals[i][0]) {
                ans++;
            } else {
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        return ans;
    }
};
