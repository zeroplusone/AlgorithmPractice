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
        int rval=postorder[n-1];
        TreeNode* root=new TreeNode(rval);
        
        int rindex=0;
        for(int i=0;i<inorder.size();++i) {
            if(inorder[i]==rval) {
                rindex=i;
                break;
            }
        }
        vector<int> inl(inorder.begin(), inorder.begin()+rindex);
        vector<int> inr(postorder.begin(), postorder.begin()+rindex);
        
        vector<int> postl(inorder.begin()+rindex+1, inorder.end());
        vector<int> postr(postorder.begin()+rindex, postorder.end()-1);

        root->left=buildTree(inl, inr);
        root->right=buildTree(postl, postr);
        return root;
    }
};
