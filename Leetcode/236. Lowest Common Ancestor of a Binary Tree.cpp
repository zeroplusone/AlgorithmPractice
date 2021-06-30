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
        unordered_set<int> pparent;
        traverse(root, p, pparent, true);
        ans=nullptr;
        traverse(root, q, pparent, false);
        return ans;
    }
    
    bool traverse(TreeNode* root, TreeNode* target, unordered_set<int>& pparent, bool isP) {
        if(root==nullptr) {
            return false;
        }
        
        if(root->val==target->val) {
            if(isP) {
                pparent.insert(root->val);
            } else {
                if(ans==nullptr && pparent.count(root->val)!=0) {
                    ans=root;
                }
            }
            return true;
        }
        
        bool isParent=traverse(root->left, target, pparent, isP) || traverse(root->right, target, pparent, isP);
        if(isParent) {
            if(isP) {
                pparent.insert(root->val);
            } else {
                if(ans==nullptr && pparent.count(root->val)!=0) {
                    ans=root;
                }
            }
        }
        return isParent;
    }

};
