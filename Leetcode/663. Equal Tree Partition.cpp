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
    bool checkEqualTree(TreeNode* root) {
        int sum=presum(root);
        return traverse(root->left, sum) || traverse(root->right, sum);
    }
    
    int presum(TreeNode* root) {
        if(root==nullptr) {
            return 0;
        }
        
        root->val=root->val+presum(root->left)+presum(root->right);
        return root->val;
    }
    
    bool traverse(TreeNode* root, int& sum) {
        if(root==nullptr) {
            return false;
        }
        return root->val==sum-root->val || traverse(root->right, sum) || traverse(root->left, sum);
        
    }
};
