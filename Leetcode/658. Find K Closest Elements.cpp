class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int mid=lower_bound(arr.begin(), arr.end(), x)-arr.begin();
        if(mid==n || mid>0 && abs(arr[mid]-x)>=abs(arr[mid-1]-x)) {
            mid--;
        }
        int beg=mid-1, end=mid+1;
        for(int i=1;i<k;++i) {
            if(beg<0) {
                end++;
            }else if(end>=n) {
                beg--;
            } else {
                if(abs(arr[beg]-x)<=abs(arr[end]-x)) {
                    beg--;
                } else {
                    end++;
                }
            }
        }
        vector<int> ans(k);
        for(int i=0;i<k;++i) {
            ans[i]=arr[beg+i+1];
        }
        return ans;
    }
};
