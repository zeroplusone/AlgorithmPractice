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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        traverse(root, low, high, ans);
        return ans;
    }
    
    void traverse(TreeNode* root, int& low, int& high, int& ans) {
        if(root==nullptr) {
            return;
        }
        
        if(root->val>=low&&root->val<=high) {
            ans+=root->val;
        }
        traverse(root->left, low, high, ans);
        traverse(root->right, low, high, ans);
    }
};
