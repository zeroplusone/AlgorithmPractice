class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string ppattern=p(pattern);
        vector<string> ans;
        for(int i=0;i<words.size();++i) {
            if(p(words[i])== ppattern) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
    
    string p(string str) {
        unordered_map<char, char> mapping;
        int cnt=0;
        string ret="";
        for(int i=0;i<str.length();++i){
            if(mapping.count(str[i])==0) {
                mapping[str[i]]='a'+cnt;
                cnt++;
            } 
            ret+=mapping[str[i]];
        }
        return ret;
    }
};
