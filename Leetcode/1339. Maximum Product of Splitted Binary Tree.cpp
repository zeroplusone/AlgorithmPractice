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
    int maxProduct(TreeNode* root) {
        long long int ans=0;
        traverse(root);
        solve(root, root->val, ans);
        long long int mod=1e9+7;
        return ans%mod;
    }
    
    int traverse(TreeNode* root) {
        if(root==nullptr) {
            return 0;
        }
        
        int sum=root->val+traverse(root->left)+traverse(root->right);
        root->val=sum;
        return sum;
    }
    
    void solve(TreeNode* root, int& total, long long int& ans) {
        if(root==nullptr) {
            return;
        }
        if(root->left!=nullptr) {
            long long int subSum=root->left->val;
            ans=max(ans, subSum*(total-subSum));    
        }
        if(root->right!=nullptr) {
            long long int subSum=root->right->val;
            ans=max(ans, subSum*(total-subSum));    
        }
        
        solve(root->left, total, ans);
        solve(root->right, total, ans);

    }
};
