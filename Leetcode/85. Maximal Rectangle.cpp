class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0;
        int m=matrix.size();
        int n=m==0?0:matrix[0].size();
        vector<int> left(n, 0);
        vector<int> right(n, n);
        vector<int> height(n, 0);
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                height[j]=matrix[i][j]=='0'?0:height[j]+1;
            }
            
            int l=0;
            for(int j=0;j<n;++j) {
                if(matrix[i][j]=='0') {
                    l=j+1;
                    left[j]=0;
                } else {
                    left[j]=max(left[j], l);
                }
            }
            
            int r=n;
            for(int j=n-1;j>=0;--j) {
                if(matrix[i][j]=='0') {
                    r=j;
                    right[j]=n;
                } else {
                    right[j]=min(right[j], r);
                }
            }
            
            for(int j=0;j<n;++j) {
                ans=max(ans, (right[j]-left[j])*height[j]);
            }
        }
        return ans;
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        // vector<int> col(n, 0);
        // int row=0;
        // for(int i=0;i<m;++i) {
        //     for(int j=0;j<n;++j) {
        //         if(matrix[i][j]=='1') {
        //             dp[i][j]=1;
        //             if(i==0&&j==0) {
        //                 dp[i][j]=1;
        //             } else if(i==0) {
        //                 if(dp[i][j-1]>0) {
        //                     dp[i][j]+=dp[i][j-1];
        //                 }
        //                 row+=1;
        //             } else if(j==0) {
        //                 if(dp[i-1][j]>0) {
        //                     dp[i][j]+=dp[i-1][j];
        //                 }
        //                 col[j]=col[j]+1;
        //             } else {
        //                 col[j]=col[j]+1;
        //                 row+=1;
        //                 if(dp[i-1][j]>0 && dp[i][j-1]>0 && dp[i-1][j-1]>0 ) {
        //                     dp[i][j]=max(dp[i][j], dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+1);
        //                 }
        //             }
        //             ans=max(ans, dp[i][j]);    
        //             ans=max(ans, row);    
        //             ans=max(ans, col[j]);    
        //         } else {
        //             col[j]=0;
        //             row=0;
        //         }
        //     }
        //     row=0;
        // }
        // return ans;
    }
};

 
