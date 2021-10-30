class Solution {
public:
    string longestDupSubstring(string s) {
        int l=0, r=s.length()-1;
        string ans="", ret="";
        while(l<r) {
            int mid=(l+r+1)>>1;
            ret=canbe(s, mid);
            if(ret.length()>0) { 
                l=mid;
                ans=ret.length()>ans.length()?ret:ans;
            } else {
                r=mid-1;
            }
        }
        return canbe(s, r);
    }
    
    string canbe(string& s, int len) {
        unordered_map<long long int, vector<int>> hashes;
        long long int h=0;
        long long int mod=1e9+7;
        for(int i=0;i<len;++i) {
            h=((h*26)%mod+(s[i]-'a'))%mod;
        }
        hashes[h].push_back(0);
        long long int base=power(26, len-1, mod);
        for(int i=len;i<s.length();++i) {
            h=((h-(s[i-len]-'a')*base)%mod+mod)%mod;
            h=(h*26+(s[i]-'a'))%mod;
            if(hashes.count(h)!=0) {
                string now=s.substr(i-len+1, len);
                for(int j=0;j<hashes[h].size();++j) {
                    if(s.substr(hashes[h][j], len)==now) {
                        return now;
                    }
                }
            } 
            hashes[h].push_back(i-len+1);
        }
        return "";
    }
    
    long long int power(int base, int p, int mod) {
        long long int ret=base;
        if(p==0) {
            return 1;
        } else if(p==1) {
            return (long long int)base;
        } else {
            long long int half=power(base, p/2, mod);
            if(p%2==0) {
                return half*half%mod;
            } else {
                return (half*half%mod)*base%mod;
            }
        }
    }
};
