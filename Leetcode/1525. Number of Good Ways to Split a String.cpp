class Solution {
public:
    int numSplits(string s) {
        unordered_map<char, int> pre, post;
        int ans=0;
        for(int i=0;i<s.length();++i) {
            post[s[i]]++;
        }
        
        for(int i=0;i<s.length();++i) {
            pre[s[i]]++;
            post[s[i]]--;
            if(post[s[i]]==0) {
                post.erase(post.find(s[i]));
            }
            if(pre.size()==post.size()) {
                ans++;
            }
        }
        return ans;
    }
};
