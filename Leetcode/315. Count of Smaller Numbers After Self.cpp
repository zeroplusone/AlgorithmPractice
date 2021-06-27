class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();

        vector<int> ans(n, 0);
        vector<pair<int, int>> arr(n);
        for(int i=0;i<nums.size();++i) {
            arr[i]=make_pair(i, nums[i]);
        }
        solve(0, n-1, arr, ans);
        return ans;
    }
    
    vector<pair<int, int>> solve(int beg, int end, vector<pair<int, int>>& arr, vector<int>& ans) {
        if(beg>end) {
            return vector<pair<int, int>>(0);
        } else if(end-beg==0) {
            return vector<pair<int, int>>{arr[beg]};
        }
        int mid=(beg+end)/2;
        vector<pair<int, int>> left=solve(beg, mid, arr, ans);
        vector<pair<int, int>> right=solve(mid+1, end, arr, ans);

        int len = end-beg+1;
        vector<pair<int, int>> ret(len);
        int l=0, r=0;
        int smaller=0;
        for(int i=0;i<len;++i){
            if(l==left.size()) {
                ret[i]=right[r++];
            } else if(r==right.size()){
                ans[left[l].first]+=smaller;
                ret[i]=left[l++];
            } else {
                if(left[l].second<=right[r].second) {
                    ans[left[l].first]+=smaller;
                    ret[i]=left[l++];
                } else {
                    ret[i]=right[r++];
                    smaller++;
                } 
            }
        }

        return ret;
        
    }
};
