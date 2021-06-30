/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans=nullptr;
        traverse(root, p, q);
        return ans;
    }
    
    bool traverse(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) {
            return false;
        }
        
        int find=0;
        
        if(root->val==p->val || root->val==q->val) {
            find++;
        }
        
        if(traverse(root->left, p, q)) {
           find++;
        }
        
        if(traverse(root->right, p, q)) {
            find++;
        }
        
        if(ans==nullptr && find==2) {
            ans=root;
        }
        return find>0;
    }

};
