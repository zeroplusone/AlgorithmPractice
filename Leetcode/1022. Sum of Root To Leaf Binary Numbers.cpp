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
    int sumRootToLeaf(TreeNode* root) {
        int ans=0, sum=0;
        solve(root, sum, ans);
        return ans;
    }
    
    void solve(TreeNode* root, int& sum, int& ans) {
        if(root==nullptr) {
            return;
        }
        sum=sum<<1|root->val;
        if(root->left==nullptr && root->right==nullptr) {
            ans+=sum;
        } else{
            solve(root->left, sum, ans);
            solve(root->right, sum, ans);    
        }
        sum=sum>>1;
        
    }
};
  
