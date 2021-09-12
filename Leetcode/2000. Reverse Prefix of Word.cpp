class Solution {
public:
    string reversePrefix(string word, char ch) {
        int en=0;
        bool flag=false;
        for(;en<word.size();++en) {
            if(word[en]==ch) {
                flag=true;
                break;
            }
        }
        if(flag) {
            for(int i=0;i<=en/2;++i) {
                char tmp=word[i];
                word[i]=word[en-i];
                word[en-i]=tmp;
            }
        }
        return word;
    }
};
