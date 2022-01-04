class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) {
            return 1;
        }
        int digit=(int)log2(n)+1;
        long long int mask=1;
        mask=(mask<<digit)-1;
        return n^mask;
    }
};
