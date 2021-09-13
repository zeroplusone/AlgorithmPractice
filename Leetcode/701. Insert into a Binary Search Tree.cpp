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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr) {
            return new TreeNode(val);
        }
        TreeNode* parent, *now=root;
        while(now!=nullptr) {
            parent=now;
            if(now->val<val) {
                now=now->right;
            } else {
                now=now->left;
            }
        }
        if (parent->val > val) {
            parent->left=new TreeNode(val);
        } else {
            parent->right=new TreeNode(val);
        }
        return root;
    }
};
