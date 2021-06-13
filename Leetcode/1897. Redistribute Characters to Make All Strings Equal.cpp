class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> cnt(26, 0);
        for(auto word:words) {
            for(auto w:word) {
                cnt[w-'a']++;
            }
        }
        for(int i=0;i<26;++i) {
            if(cnt[i]%words.size()!=0) {
                return false;
            }
        }
        return true;
    }
};
