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
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans=false;
        DFS(root, 0, targetSum, ans);
        return ans;
    }
    
    void DFS(TreeNode* root, int sum, int& targetSum, bool& ans) {
        if(root==nullptr) {
            return;    
        } if(root->left==nullptr && root->right==nullptr) {
            if(sum+root->val==targetSum) {
                ans=true;
            }
            return;
        }
        
        DFS(root->left, sum+root->val, targetSum, ans);
        DFS(root->right, sum+root->val, targetSum, ans);
    }
};
