class Solution {
public:
    int minSwaps(string s) {
        int mismatch=0;
        int left=0;
        for(int i=0;i<s.length();++i) {
            if(s[i]=='[') {
                left++;
            } else if(left==0) {
                mismatch++;
            } else {
                left--;
            }
        }
        return (mismatch+1)/2;
    }
};
