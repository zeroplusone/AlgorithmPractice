class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string prefix="";
        for(int i=0;i<words.size();++i) {
            prefix+=words[i];
            if(prefix==s) {
                return true;
            }
        }
        return false;
    }
};
