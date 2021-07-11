class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, vector<int>> cnt;
        for(int i=0;i<s.length();++i) {
            cnt[s[i]].push_back(i);
        }
        int ans=0;
        for(auto c:cnt){
            if(c.second.size()>=2) {
                for(auto c2:cnt) {
                   int find=upper_bound(c2.second.begin(), c2.second.end(), c.second[0])-c2.second.begin();
                    if(find!=c2.second.size() && c2.second[find]<c.second[c.second.size()-1]) {
                        ans++;
                    }
                    
                }
            }
        }
        return ans;
    }
};
