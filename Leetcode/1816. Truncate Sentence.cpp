class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans;
        int space=0;
        for(auto c: s) {
            if(c==' ') {
                space++;
                if(space==k) {
                    break;
                }
            }
            ans+=c;
        }
        return ans;
    }
};
