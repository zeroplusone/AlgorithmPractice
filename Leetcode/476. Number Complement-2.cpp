class Solution {
public:
    int findComplement(int num) {
        int digit=(int)log2(num)+1;
        long long int mask=1;
        mask=(mask<<digit)-1;
        return num^mask;
    }
};
