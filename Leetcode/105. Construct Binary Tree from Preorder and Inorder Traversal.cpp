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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(0, preorder.size(), 0, inorder.size(), preorder, inorder);
    }
    
    TreeNode* solve(int ps, int pe, int is, int ie, vector<int>& preorder, vector<int>& inorder) {
        
        if(ps>=pe || is>=ie) {
            return nullptr;
        }
        
        int root_val = preorder[ps];
        TreeNode* root = new TreeNode(root_val);

        int inroot=find(inorder.begin()+is, inorder.begin()+ie, root_val)-inorder.begin();

        int left_size=inroot-is;
        root->left=solve(ps+1, ps+1+left_size, is, inroot, preorder, inorder);
        root->right=solve(ps+left_size+1, pe, inroot+1, ie, preorder, inorder);
        
        return root;
    }
    
};
