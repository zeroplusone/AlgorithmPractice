class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt=0;
        unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int i=0;i<s.length()/2;++i) {
            if(vowels.count(s[i])!=0) {
                cnt++;
            }
        }
        for(int i=s.length()/2;i<s.length();++i) {
            if(vowels.count(s[i])!=0) {
                cnt--;
            }
        }
        return cnt==0;
    }
};
