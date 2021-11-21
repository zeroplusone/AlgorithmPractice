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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        if(n==0) {
            return nullptr;
        }
        return solve(inorder, postorder, 0, n-1, 0, n-1);
    }
    
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr) {
        if(ir-il<0) {
            return nullptr;
        }
        int rval=postorder[pr];
        TreeNode* root=new TreeNode(rval);
        
        int lsize=0;
        for(int i=il;i<=ir;++i, lsize++) {
            if(inorder[i]==rval) {
                break;
            }
        }

        root->left=solve(inorder, postorder, il, il+lsize-1, pl, pl+lsize-1);
        root->right=solve(inorder, postorder, il+lsize+1, ir, pl+lsize, pr-1);
        return root;
    }
};
