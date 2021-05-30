class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return toValue(firstWord)+toValue(secondWord)==toValue(targetWord);
    }
    
    int toValue(string s) {
        int ret=0;
        for(int i=0;i<s.length();++i) {
            ret=ret*10+s[i]-'a';
        }
        return ret;
    }
};
