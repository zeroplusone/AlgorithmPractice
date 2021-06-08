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
        int index=0;
        unordered_map<int, int> in_index;
        for(int i=0;i<inorder.size();++i) {
            in_index[inorder[i]]=i;
        }
        return solve(index, 0, inorder.size()-1, preorder, in_index);
    }
    
    TreeNode* solve(int& index, int beg, int end, vector<int>& preorder, unordered_map<int, int>& in_index) {
        
        if(beg>end) {
            return nullptr;
        }
        
        int root_val = preorder[index++];
        TreeNode* root = new TreeNode(root_val);

        int inroot=in_index[root_val];

        root->left=solve(index, beg, inroot-1, preorder, in_index);
        root->right=solve(index, inroot+1, end, preorder, in_index);
        
        return root;
    }
    
};
