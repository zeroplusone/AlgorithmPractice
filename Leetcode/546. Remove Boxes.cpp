class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        vector<vector<vector<int>>> dp(100, vector<vector<int>>(100, vector<int>(100, 0)));
        return solve(0, boxes.size()-1, 0, dp, boxes);
    }
    
    int solve(int l, int r, int k, vector<vector<vector<int>>>& dp, vector<int>& boxes) {
        if(l>r) {
            return 0;
        }
        
        while(r>l && boxes[r]==boxes[r-1]) {
            r--;
            k++;
        }
        
        if(dp[l][r][k]!=0) {
            return dp[l][r][k];
        }

        dp[l][r][k]=solve(l, r-1, 0, dp, boxes)+(k+1)*(k+1);
        for(int i=l;i<r;++i) {
            if(boxes[i]==boxes[r]) {
                dp[l][r][k]=max(dp[l][r][k], solve(l, i, k+1, dp, boxes)+solve(i+1, r-1, 0, dp, boxes));   
            }
        }
        return dp[l][r][k];
    }
};
