class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken;
        for(int i=0;i<brokenLetters.length();++i) {
            broken.insert(brokenLetters[i]);
        }
        
        int ans=0;
        bool hit=false;
        for(int i=0;i<text.length();++i) {
            if(text[i]==' ') {
                ans+=hit?0:1;
                hit=false;
            } else {
                if(broken.count(text[i])!=0){
                    hit=true;
                }
            }
        }
        ans+=hit?0:1;
        return ans;
    }
};
