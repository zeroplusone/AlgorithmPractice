class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0){
            return 0;
        }
        int ans=0;
        int r=matrix.size(), c=matrix[0].size();
        vector<vector<int> > dp(2, vector<int>(c+1, 0));
        for(int x=0;x<r;++x){
            for(int y=1;y<=c;++y){
                if(x==0) {
                    dp[1][y]=matrix[x][y-1]-'0';
                } else if(matrix[x][y-1]=='1'){
                    dp[1][y]=min(dp[0][y], min(dp[1][y-1], dp[0][y-1]))+1;
                } else {
                    dp[1][y]=0;
                }
                ans=max(ans, dp[1][y]);
            }
            dp[0]=dp[1];
        }
        

        return ans*ans;
    }
};
