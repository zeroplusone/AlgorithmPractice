class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;++i) {
            sum+=nums[i];
        }
        
        if(sum%k!=0) {
            return false;
        }
        
        int target=sum/k;
        sort(nums.begin(), nums.end());
        
        if(nums[n-1]>target) {
            return false;
        }
        
        int v=0;
        bool ans=true;
        for(int i=0;i<k&&ans;++i) {
            ans&=find(nums, v, 0, target);
        }
        return ans;
    }
    
    bool find(vector<int>& nums, int& v, int now, int& target) {
        if(now==target) {
            return true;
        }
        
        bool ret=false;
        for(int i=nums.size()-1;i>=0;--i) {
            int mask=1<<i;
            int visit=v&mask;
            if(visit==0 && now+nums[i]<=target) {
                v|=mask;
                ret|=find(nums, v, now+nums[i], target);
                if(ret) {
                    break;
                } else {
                    v&=~mask;
                }
            }
        }
        return ret;
    }
    
    
};
