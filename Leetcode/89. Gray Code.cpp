class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==1) {
            return vector<int>{0, 1};
        }
        
        vector<int> last=grayCode(n-1);
        vector<int> ans(last.size()*2);
        int base=pow(2, n-1);
        for(int i=0;i<last.size();++i) {
            if(i%2==0) {
                ans[i*2]=last[i];
                ans[i*2+1]=base+last[i];
            } else {
                ans[i*2]=base+last[i];
                ans[i*2+1]=last[i];
            }
        }
        return ans;
    }
};
