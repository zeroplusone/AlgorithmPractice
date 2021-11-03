class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) {
            return s;
        }
        int delta=numRows*2-2;
        string ans=s;
        int index=0;
        for(int i=0;i<numRows;++i) {
            int j=i;
            while(j<s.length()) {
                ans[index++]=s[j];
                if(i!=0 && i!=numRows-1 && j+2*(numRows-i-1)<s.length()) {
                    ans[index++]=s[j+2*(numRows-i-1)];
                }
                j+=delta;
            }
        }
        return ans;
    }
};
