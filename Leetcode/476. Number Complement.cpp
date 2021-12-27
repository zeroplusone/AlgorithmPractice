class Solution {
public:
    int findComplement(int num) {
        int digit=0;
        int tmp=num;
        while(tmp>0) {
            digit++;
            tmp=tmp>>1;
        }
        
        int ans=0;
        for(int i=digit-1;i>=0;--i) {
            ans|=(1<<i)&num^(1<<i);
        }
        return ans;
    }
};
