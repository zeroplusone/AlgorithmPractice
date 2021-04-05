class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {

        for(int i=0;i<A.size()-1;) {
            if(A[i]-i==0) {
                i++;
            } else if(A[i+1]-i==0 && A[i]-i==1) {
                i+=2;
            } else {
                return false;
            }
        }
        return true;
    }
};
