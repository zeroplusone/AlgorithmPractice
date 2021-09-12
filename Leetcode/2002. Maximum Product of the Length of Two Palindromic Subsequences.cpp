class Solution {
public:
    int maxProduct(string s) {
        int ans=1;
        int n=s.length();
        vector<int> palin;
        findPalin(0, n-1, s, 0, palin);
        // for(int i=0;i<palin.size();++i) {
        //     cout<<i<<" ";
        //     print(palin[i], n);
        // }
        for(int i=0;i<palin.size();++i) {
            for(int j=i+1;j<palin.size();++j) {
                if((palin[i]&palin[j])==0) {
                    int l1=findLen(palin[i], n);
                    int l2=findLen(palin[j], n);
                    ans=max(ans, l1*l2);    
                }
            }
        }
        return ans;
    }
    
    void print(int& mask, int& n) {
        for(int i=0;i<n;++i) {
            if(mask&(1<<i)) {
                cout<<"1";
            } else {
                cout<<"0";
            }
        }
        cout<<endl;
    }
    
    int findLen(int& mask, int& n) {
        int cnt=0;
        for(int i=0;i<n;++i) {
            if(mask&(1<<i)) {
                cnt++;
            }
        }
        return cnt;
    }
    
    void findPalin(int st, int en, string& s, int mask, vector<int>& palin) {
        if(st>en) {
            return;
        } 
        for(int i=st;i<=en;++i) {
            int now=mask|(1<<i);
            palin.push_back(now);
            for(int j=i+1;j<=en;++j) {
                if(s[i]==s[j]) {
                    palin.push_back(now|(1<<j));
                    findPalin(i+1, j-1, s, now|(1<<j), palin);
                }
            }
        }
        
    }
};
