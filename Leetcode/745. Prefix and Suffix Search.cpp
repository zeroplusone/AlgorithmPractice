class WordFilter {
public:
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();++i) {
            string pre="";
            for(int j=0;j<words[i].length();++j) {
                pre=pre+words[i][j];
                prefix_map[pre].insert(i);
            }
            string suf="";
            for(int j=words[i].length()-1;j>=0;--j) {
                suf=words[i][j]+suf;
                suffix_map[suf].insert(i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        for(auto mpre: prefix_map[prefix]) {
            if(suffix_map[suffix].count(mpre)!=0) {
                return mpre;
            }
        }
        return -1;
    }
private:
    unordered_map<string, set<int, greater<int>>> prefix_map;
    unordered_map<string, set<int, greater<int>>> suffix_map;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
