class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        vector<unordered_set<int>> dp(n);
        
        for(int i=0;i<n;++i) {
            for(int j=0;j<n-i;++j) {
                if(i==0) {
                    dp[j].insert(j+i);
                } else if(i==1 && s[j]==s[j+i]){
                    dp[j].insert(j+i);
                } else if (s[j]==s[j+i]&&dp[j+1].count(j+i-1)!=0){
                    dp[j].insert(j+i);
                }
            }
        }
        
        queue<int> que;
        que.push(0);
        int ans=0;
        vector<bool> v(n, false);
        v[0]=true;
        while(!que.empty()) {
            int size=que.size();
            for(int i=0;i<size;++i) {
                int now=que.front();
                que.pop();

                if(dp[now].count(n-1)!=0) {
                    return ans;
                } 
                for(auto it=dp[now].begin();it!=dp[now].end();++it) {
                    if(!v[(*it)+1]){
                        que.push((*it)+1);
                        v[(*it)+1]=true;
                    }
                }
            }
            ans++;
            
        }
        return ans;
    }
};
