class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> sta;
        for(int i=0;i<temperatures.size()-1;++i) {
            sta.push(i);
            
            while(!sta.empty() && temperatures[i+1]>temperatures[sta.top()]) {
                ans[sta.top()]=i+1-sta.top();
                sta.pop();
            }
        }
        return ans;
    }
};
