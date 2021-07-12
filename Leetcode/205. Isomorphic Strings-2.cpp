class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> replace;
        unordered_set<char> tc;
        for(int i=0;i<s.length();++i) {
            if(replace.count(s[i])==0 && tc.count(t[i])==0) {
                replace[s[i]]=t[i];    
                tc.insert(t[i]);
            } else {
                if(replace[s[i]]!=t[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
