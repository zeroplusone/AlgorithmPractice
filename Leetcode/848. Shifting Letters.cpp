class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int sum=0, shift;
        for(int i=shifts.size()-1;i>=0;--i) {
            sum=(sum+shifts[i])%26;
            s[i]=(sum+s[i]-'a')%26+'a';
        }
        
        return s;
    }
};
