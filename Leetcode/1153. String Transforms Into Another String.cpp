class Solution {
public:
    bool canConvert(string str1, string str2) {
        if(str1==str2) {
            return true;
        }
        unordered_map<char, char> convert;
        unordered_set<char> cnt;
        
        for(int i=0;i<str1.length();++i) {
            if(convert.count(str1[i])==0) {
                convert[str1[i]]=str2[i];
                cnt.insert(str2[i]);
            } else if(convert[str1[i]]!=str2[i]) {
                return false;
            }
        }
        
        return cnt.size()<26;
    }
};
