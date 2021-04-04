class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        long long int sum=0;
        int maxVal=0, diff;
        vector<int> copy(nums1);
        sort(copy.begin(), copy.end());
        
        int mod = 1e9+7;
        for(int i=0;i<nums1.size();++i) {
            diff=abs(nums1[i]-nums2[i]);
            sum=(sum+diff)%mod;
            auto low =lower_bound(copy.begin(), copy.end(), nums2[i]);
            if(low!=copy.end()) {
                maxVal=max(maxVal, diff-abs(*low-nums2[i]));
            } 
            if(low!=copy.begin()) {
                maxVal=max(maxVal, diff-abs(*prev(low)-nums2[i]));
            }            
        }

        return (sum+mod-maxVal)%mod;
    }
};
