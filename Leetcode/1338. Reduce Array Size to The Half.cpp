class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int, int> cnt;
        for(int i=0;i<n;++i) {
            cnt[arr[i]]++;
        }
        priority_queue<int> pq;
        for(auto c:cnt) {
            pq.push(c.second);
        }
        int ans=0;
        int sum=0;
        while(!pq.empty()) {
            sum+=pq.top();
            ans++;
            pq.pop();
            if(sum>=n/2) {
                break;
            }
        }
        return ans;
    }
};
