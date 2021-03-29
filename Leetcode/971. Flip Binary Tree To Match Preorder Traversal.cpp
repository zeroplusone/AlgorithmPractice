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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ans(0);
        solve(root, nullptr, 0, voyage, ans);
        
        return ans;
    }
    
    int solve(TreeNode* root, TreeNode* parent, int index, vector<int>& voyage, vector<int>& ans) {
        if(root==nullptr) {
            ans.push_back(-1);
            return -1;
        }
        
        if(root->val != voyage[index]) {
            if(parent==nullptr || parent->right==nullptr) {
                ans.clear();
                ans.push_back(-1);
                return -1;
            } 
            if(parent->right->val==voyage[index]) {
                ans.push_back(parent->val);
                TreeNode* tmp = parent->left;
                parent->left = parent->right;
                parent->right = tmp;
                root=parent->left;
            } else {
                ans.clear();
                ans.push_back(-1);
                return -1;
            }
            
        }
        
        int lastLeft;
        
        if(root->left==nullptr) {
            lastLeft = index;
        } else {
            lastLeft = solve(root->left, root, index+1, voyage, ans);
        }
        
        if(lastLeft==-1) {
            return -1;
        }
        
        int lastRight;
        if(root->right==nullptr) {
            lastRight = lastLeft;
        } else {
            lastRight = solve(root->right, root, lastLeft+1, voyage, ans);    
        }
        
        return lastRight;
    }
    
};
