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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr && root2==nullptr) {
            return true;
        } else if(root1==nullptr || root2==nullptr) {
            return false;   
        } else if(root1->val==root2->val) {
            if(equals(root1->left, root2->left) && equals(root1->right, root2->right)) {
                return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
            } else if(equals(root1->left, root2->right) && equals(root1->right, root2->left)) {
                return flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
            } 
        }
        
        return false;
        
    }
    
    bool equals(TreeNode* n1, TreeNode* n2) {
        if(n1==nullptr && n2==nullptr) {
            return true;
        } else if(n1!=nullptr && n2!=nullptr && n1->val==n2->val) {
            return true;
        }
        return false;
    }
};
