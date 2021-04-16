class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> sta;
        pair<char,int> pi;
        for(int i=0;i<s.length();++i) {
            if(sta.empty()) {
                sta.push(make_pair(s[i], 1));
            } else {
                pi=sta.top();
                if(pi.first==s[i]) {
                    sta.pop();
                    if(pi.second+1!=k) {
                        sta.push(make_pair(pi.first, pi.second+1));
                    }
                } else {
                    sta.push(make_pair(s[i], 1));
                }
            }
        }
        
        string ans="";
        while(!sta.empty()) {
            pi=sta.top();
            for(int i=0;i<pi.second;++i) {
                ans+=pi.first;
            }
            sta.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
