class Solution {
public:
    bool isValidSerialization(string preorder) {
        int cnt=1;
        int n=preorder.length();
        for(int i=0;i<n;++i) {
            while(i<n&&preorder[i]!=',') {
                i++;
            }
            
            cnt--;
            if(cnt<0) {
                return false;
            }

            if(preorder[i-1]!='#'){
                cnt+=2;
            }
            
            
        }
        return cnt==0;

    }
};
