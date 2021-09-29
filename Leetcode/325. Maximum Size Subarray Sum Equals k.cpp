class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=1;i<n;++i) {
            nums[i]=nums[i-1]+nums[i];
        }
        
        // n2 -n1 =k
        unordered_map<int, int> m;
        m[k]=-1;
        int ans=0;
        for(int i=0;i<n;++i) {
            if(m.count(nums[i])!=0) {
                ans=max(ans, i-m[nums[i]]);
            }
            
            if(m.count(k+nums[i])==0) {
                m[k+nums[i]]=i;    
            }

        }
        return ans;
    }
};
