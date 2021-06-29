class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        queue<int> que;
        
        int one=0;
        for(int i=0;i<nums.size();++i) {
            if(nums[i]==1) {
                one++;    
            } else {
                if(k!=0) {
                    if(que.size()==k) {
                    one=i-que.front();
                    que.pop();
                    } else {
                        one++;
                    }
                    que.push(i);
                } else {
                    one=0;
                }
            }
            ans=max(ans, one);
        }
        return ans;
    }
};
