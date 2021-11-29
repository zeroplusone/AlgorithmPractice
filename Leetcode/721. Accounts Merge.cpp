class Solution {
public:

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string, int> rev;
        vector<int> p(n);
        
        for(int i=0;i<n;++i) {
            p[i]=i;
        }
        
        for(int i=0;i<n;++i) {
            for(int j=1;j<accounts[i].size();++j) {
                if(rev.count(accounts[i][j])==0) {
                    rev[accounts[i][j]]=i;
                } else {
                    int xp=findp(rev[accounts[i][j]], p);
                    int yp=findp(i, p);
                    p[yp]=xp;
                    rev[accounts[i][j]]=xp;
                }
            }
        }
        
        vector<set<string>> s(n);
        unordered_map<int, int> index;
        for(int i=0;i<n;++i) {
            int pi=findp(i, p);
            for(int j=1;j<accounts[i].size();++j) {
                s[pi].insert(accounts[i][j]);    
            }
        }
        
        vector<vector<string>> ans;
        for(int i=0;i<n;++i) {
            if(s[i].size()!=0) {
                vector<string> a;
                a.push_back(accounts[i][0]);
                for(auto j: s[i]) {
                    a.push_back(j);
                }
                ans.push_back(a);
            }
        }
        return ans;
    }
    
    int findp(int now, vector<int>& p) {
        if(now==p[now]) {
            return now;
        } else {
            return p[now]=findp(p[now], p);
        }
    }
};
