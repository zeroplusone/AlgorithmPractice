class Solution {
public:
    bool isThree(int n) {
        int div=0;
        for(int i=1;i<=n;++i) {
            if(n%i==0) {
                div++;
            }
            if(div>3) {
                return false;
            }
        }
        return div==3;
     }
};
