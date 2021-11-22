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
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root==nullptr) {
            return root;
        } else if(root->val==key) {
            if(root->right==nullptr && root->left==nullptr) {
                delete root;
                return nullptr;
            } else if(root->right==nullptr) {
                return root->left;
            } else if(root->left==nullptr) {
                return root->right;
            }else {
                TreeNode* rmin=root->right;
                while(rmin->left!=nullptr) {
                    rmin=rmin->left;
                }
                swap(root->val, rmin->val);
                root->right=deleteNode(root->right, key);
            }
        } else if(root->val<key) {
            root->right=deleteNode(root->right, key);
        } else {
            root->left=deleteNode(root->left, key);
        }
        return root;
    }

};
