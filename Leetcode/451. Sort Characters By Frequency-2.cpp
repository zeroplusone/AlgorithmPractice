class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(int i=0;i<s.length();++i) {
            m[s[i]]++;
        }
        
        vector<vector<char>> cnt(s.length()+1, vector<char>(0));
        for(auto i: m) {
            cnt[i.second].push_back(i.first);
        }
        string ans="";
        for(int i=s.length();i>=0;--i) {
            for(int j=0;j<cnt[i].size();++j) {
                ans+=string(i, cnt[i][j]);
            }
        }
        return ans;
    }
};
