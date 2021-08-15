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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        solve(root, ans);
        
        return ans;
    }
    
    int solve(TreeNode* root, int& ans) {
        if(root==nullptr) {
            return 0;
        }
        
        int left=0, right=0;
        if(root->left!=nullptr) {
            left=solve(root->left, ans)+1;    
        }
        if(root->right!=nullptr) {
            right=solve(root->right, ans)+1;    
        }
        
        ans=max(ans, left+right);
        return max(left, right);
    }
};
