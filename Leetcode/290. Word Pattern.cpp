class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m;
        string now;
        int j=0;
        unordered_set<string> ss;
        for(int i=0;i<pattern.length();++i) {
            now="";
            while(j<s.length() && s[j]!=' ') {
                now+=s[j];
                j++;
            }
            if(now=="") {
                return false;
            } 
            j++;
            if(m.count(pattern[i])==0) {
                m[pattern[i]]=now;
                ss.insert(now);
            } else {
                if(m[pattern[i]]!=now) {
                    return false;
                }
            }
        }
        
        for(int i=j;i<s.length();++i) {
            if(s[i]!=' ') {
                return false;
            }
        }
        return m.size()==ss.size();
    }
};
