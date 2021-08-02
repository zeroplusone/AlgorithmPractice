class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4) {
            return 0;
        }
        
        // 4 O(n) pass to find the top 4 max value and top 4 min value
        vector<int> val(8, 0);
        for(int i=0;i<4;++i) {
            int minv=1e9+1, minIndex;
            int maxv=-1e9-1, maxIndex;
            for(int j=0;j<n;++j) {
                if(i==0) {
                    if(minv>nums[j]) {
                        minv=nums[j];
                        minIndex=j;
                    }
                    if(maxv<nums[j]) {
                        maxv=nums[j];
                        maxIndex=j;
                    }
                } else {
                    if(minv>=nums[j]) {
                        bool found=false;
                        for(int k=0;k<i*2;k+=2) {
                            if(val[k]==j) {
                                found=true;
                            }
                        }
                        if(!found) {
                            minv=nums[j];
                            minIndex=j;
                        }
                        
                    }
                    if(maxv<=nums[j]) {
                        bool found=false;
                        for(int k=1;k<i*2;k+=2) {
                            if(val[k]==j) {
                                found=true;
                            }
                        }
                        if(!found) {
                            maxv=nums[j];
                            maxIndex=j;
                        }
                    }
                }
            }
            val[i*2]=minIndex;
            val[i*2+1]=maxIndex;
        }

        cout<<endl;
        return min({nums[val[7]]-nums[val[0]], nums[val[1]]-nums[val[6]], nums[val[5]]-nums[val[2]], nums[val[3]]-nums[val[4]]});
    }
};
