class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0){
            return 0;
        }
        int ans=0;
        int r=matrix.size(), c=matrix[0].size();
        vector<vector<int> > dp(r+1, vector<int>(c+1, 0));
        for(int x=1;x<=r;++x){
            for(int y=1;y<=c;++y){
                if(matrix[x-1][y-1]=='1'){
                    dp[x][y]=min(dp[x-1][y], min(dp[x][y-1], dp[x-1][y-1]))+1;
                }
                ans=max(ans, dp[x][y]);
            }
        }
        

        return ans*ans;
    }
};
