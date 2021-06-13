class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int beg=0, end=removable.size(), mid;

        while(beg<end) {
            mid=(beg+end+1)/2;
            if(canbe(mid, s, p, removable)) {
                beg=mid;    
            } else {
                end=mid-1;
            }
        }
        return end;
    }
    
    bool canbe(int k, string& s, string& p, vector<int>& removable) {
        vector<bool> removed(s.length(), false);
        for(int i=0;i<k;++i) {
            removed[removable[i]]=true;
        }
        int si=0, pi=0;
        while(si<s.length() && pi<p.length()) {
            while(si<s.length() && (s[si]!=p[pi] || removed[si])) {
                si++;
            }
            
            if(s[si]==p[pi]) {
                pi++;
                si++;
            }
        }
        return pi==p.length();
    }
};
