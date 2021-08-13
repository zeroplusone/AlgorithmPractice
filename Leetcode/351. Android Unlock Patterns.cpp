class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<int> v(9, false);
        int ans=0;
        solve(-1, 0, m, n, v, ans);
        return ans;
    }
    
    void solve(int last, int now, int& m, int& n, vector<int>& v, int& ans) {
        if(now>n) {
            return;
        } else if(now>=m && now<=n) {
            ans++;
        }
        for(int i=0;i<9;++i) {
            if(!v[i]) {
                if(last!=-1) {
                    int x1=last/3;
                    int y1=last%3;
                    int x2=i/3;
                    int y2=i%3;
                    if(abs(x1-x2)%2==0 && abs(y1-y2)%2==0) {
                        int mid=((x1+x2)/2)*3+(y1+y2)/2;
                        if(!v[mid]) {
                            continue;
                        }
                    }
                }
                v[i]=true;
                solve(i, now+1, m, n, v, ans);
                v[i]=false;
            }
        }
    }
};
