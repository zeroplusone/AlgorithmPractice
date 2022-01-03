class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> t(n+1, 0);
        vector<int> bt(n+1, 0);
        
        for(int i=0;i<trust.size();++i) {
            t[trust[i][0]]++;
            bt[trust[i][1]]++;
        }
        
        int ans=-1;
        for(int i=1;i<=n;++i) {
            if(t[i]==0 && bt[i]==n-1) {
                if(ans!=-1) {
                    return -1;
                } else {
                    ans=i;    
                }
            }
        }
        
        return ans;
    }
};
