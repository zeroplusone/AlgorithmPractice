class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==0) {
            return 0;
        }
        int twol=-1, twor=-1;
        int tmp=left;
        while(tmp!=0) {
            twol++;
            tmp/=2;
        }
        
        tmp=right;
        while(tmp!=0) {
            twor++;
            tmp/=2;
        }
        
        if(twol!=twor) {
            return 0;
        } else {
            int find=pow(2, twol);
            return find|=rangeBitwiseAnd(left-find, right-find);
        }
    }
};
