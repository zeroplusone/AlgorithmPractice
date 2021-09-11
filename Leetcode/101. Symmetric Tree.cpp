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
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) {
            return true;
        }
        return equals(root->left, root->right);
    }
    
    bool equals(TreeNode* t1, TreeNode* t2) {
        if(t1==nullptr && t2==nullptr) {
            return true;
        } else if(t1!=nullptr && t2!=nullptr) {
            return t1->val==t2->val && equals(t1->left, t2->right) && equals(t1->right, t2->left);    
        }
        return false;
    }
};
