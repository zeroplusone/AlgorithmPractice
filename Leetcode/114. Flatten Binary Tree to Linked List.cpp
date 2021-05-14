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
    void flatten(TreeNode* root) {
        solve(root);
    }
    
    TreeNode* solve(TreeNode* root) {
        if(root == nullptr || root->left==nullptr && root->right==nullptr) {
            return root;
        }
        TreeNode* left=nullptr, *right=nullptr;
        if(root->left!=nullptr) {
            left=solve(root->left);
        }
        if(root->right!=nullptr) {
            right=solve(root->right);
        }
        if(left!=nullptr) {
            left->right=root->right;
            root->right=root->left;
            root->left=nullptr;
        }
        if(right!=nullptr) {
            return right;
        }else {
            return left;
        }
    }
};
