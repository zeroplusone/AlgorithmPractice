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
    TreeNode* last;
    bool isValidBST(TreeNode* root) {
        last=nullptr;
        return traverse(root);
    }
    
    bool traverse(TreeNode* root) {
        if(root==nullptr) {
            return true;
        }
        

        if(!traverse(root->left)) {
            return false;
        }
        
        if(last==nullptr || root->val>last->val) {
            last=root;
        } else {
            return false;
        }
        
        return traverse(root->right);
    }
};
