class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()==1) {
            return 0;
        } else if(nums.size()==2) {
            return abs(nums[1]-nums[0]);
        }
        
        unordered_set<int> numSet;

        int minVal=2*1e9, maxVal=0;
        for(int i=0;i<nums.size();++i) {
            minVal = min(minVal, nums[i]);
            maxVal = max(maxVal, nums[i]);
            numSet.insert(nums[i]);
        }
        int n=numSet.size();
        
        if(minVal==maxVal) {
            return 0;
        }
        
        int bucketSize=(maxVal-minVal)/(n+1);
        int bucketNum=(maxVal-minVal)/bucketSize;
        vector<int> bucketMin(bucketNum+1, 1e9);
        vector<int> bucketMax(bucketNum+1, 0);
        
        for(auto num:numSet) {
            int bucketIndex=(num-minVal)/bucketSize;
            bucketMin[bucketIndex]=min(bucketMin[bucketIndex], num);
            bucketMax[bucketIndex]=max(bucketMax[bucketIndex], num);
        }
        
        int ans=0;
        for(int i=0, j=1;i<=bucketNum && j<=bucketNum;) {
            while(j<=bucketNum && bucketMax[j]==0) {
                j++;
            }
            if(j==bucketNum+1) {
                break;
            }
            ans=max(ans, bucketMin[j]-bucketMax[i]);
            i=j;
            j++;
        }
        return ans;
    }
};
