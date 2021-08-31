class Solution {
public:
    int tribonacci(int n) {
        vector<int> T{0, 1, 1, 0};
        if(n<3) {
            return T[n];
        } 
        for(int i=3;i<=n;++i) {
            T[3]=T[0]+T[1]+T[2];
            T[0]=T[1];
            T[1]=T[2];
            T[2]=T[3];
        }
        return T[3];
    }
};
