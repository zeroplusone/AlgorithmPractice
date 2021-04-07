class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt=0, mid=s.length()>>1;
        unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int i=0;i<mid;++i) {
            if(vowels.count(s[i])!=0) {
                cnt++;
            }
            if(vowels.count(s[mid+i])!=0) {
                cnt--;
            }
        }
        return cnt==0;
    }
};
