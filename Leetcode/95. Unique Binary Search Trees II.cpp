/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> dp(n+1);
        dp[0]=vector<TreeNode*>{nullptr};
        dp[1]=vector<TreeNode*>{new TreeNode(1)};
        for(int i=2;i<=n;++i) {
            for(int j=1;j<=i;++j) {
                for(int k=0;k<dp[j-1].size();++k) {
                    for(int l=0;l<dp[i-j].size();++l) {
                        TreeNode* ans=new TreeNode(j);
                        if(j-1!=0) {
                            ans->left=build(dp[j-1][k], 0);    
                        }
                        if(i-j!=0) {
                            ans->right=build(dp[i-j][l], j);    
                        }
                        
                        dp[i].push_back(ans);
                    }
                }
                
            }
        }
        return dp[n];
    }
    
    TreeNode* build(TreeNode* dp, int base) {
        if(dp==nullptr) {
            return nullptr;
        }
        return new TreeNode(dp->val+base, build(dp->left, base), build(dp->right, base));
    }
};
