class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> v;
        int n=s.length();
        int ans=0;
        int st=0;
        for(int i=0;i<n;++i) {
            if(v.count(s[i])!=0) {
                st=max(v[s[i]]+1, st);    
            }
            ans=max(ans, i-st+1);
            v[s[i]]=i;
        }
        ans=max(ans, n-st);
        return ans;
    }
};
