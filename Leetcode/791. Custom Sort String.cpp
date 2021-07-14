class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> cnt(26, 0);
        for(int i=0;i<str.length();++i) {
            cnt[str[i]-'a']++;
        }
        string ans="";
        for(int i=0;i<order.size();++i) {
            ans+=string(cnt[order[i]-'a'], order[i]);
            cnt[order[i]-'a']=0;
        }
        for(int i=0;i<26;++i) {
            if(cnt[i]!=0) {
                ans+=string(cnt[i], 'a'+i);
            }
        }
        return ans;
    }
};
