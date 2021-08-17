class Solution {
public:
    string getPermutation(int n, int k) {
        vector<bool> v(n+1, false);
        string ans="";
        solve(0, 0, n, k, v, ans);
        return ans;
    }
    
    void solve(int digit, int now, int& n, int& k, vector<bool>& v, string& ans) {
        if(ans!="") {
            return;
        }
        if(digit==n) {
            k--;
            if(k==0) {
                ans=to_string(now);
            }
            return;
        }
        
        for(int i=1;i<=n;++i) {
            if(!v[i]) {
                v[i]=true;
                solve(digit+1, now*10+i, n, k, v, ans);
                v[i]=false;
            }
        }
    }
};
