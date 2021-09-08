class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> rcnt(26, 0);
        vector<int> mcnt(26, 0);
        for(int i=0;i<ransomNote.length();++i) {
            rcnt[ransomNote[i]-'a']++;
        }
        
        for(int i=0;i<magazine.length();++i) {
            mcnt[magazine[i]-'a']++;
        }
        
        for(int i=0;i<26;++i) {
            if(mcnt[i]<rcnt[i]) {
                return false;
            }
        }
        return true;
    }
};
