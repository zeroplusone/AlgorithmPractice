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
    int ans;
    int minCameraCover(TreeNode* root) {
        ans = 0;
        solve(root, nullptr);
        return ans;
    }
    
    void solve(TreeNode* root, TreeNode* parent) {
        if(root!=nullptr) {
            TreeNode* l = root->left;
            TreeNode* r = root->right;
            solve(l, root);
            solve(r, root);
            
            if((parent==nullptr && root->val!=1) || (l!=nullptr && l->val==0) || (r!=nullptr && r->val==0)) {
                ans++;
                root->val=1;
                if(parent!=nullptr) {
                    parent->val=1;
                }
            } 
        }
    }
};
