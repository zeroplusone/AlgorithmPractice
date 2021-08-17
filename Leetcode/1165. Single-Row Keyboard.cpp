class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> k;
        for(int i=0;i<keyboard.length();++i) {
            k[keyboard[i]]=i;
        }
        int ans=0, last=0;
        for(int i=0;i<word.length();++i) {
            ans+=abs(k[word[i]]-last);
            last=k[word[i]];
        }
        return ans;
    }
};
