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
    struct info{
        int cnt;
        int minv, maxv;
        info(int c, int minv, int maxv): cnt(c), minv(minv), maxv(maxv){};
    };

    int largestBSTSubtree(TreeNode* root) {
        int ans=0;
        traverse(root, ans);
        return ans;
    }
    
    info traverse(TreeNode* root, int& ans) {
        if(root==nullptr) {
            return info(0, 1e9, -1e9);
        }
        
        info l=traverse(root->left, ans);
        info r=traverse(root->right, ans);
        
        if(l.cnt==-1 || r.cnt==-1) {
            return info(-1, 1e9, -1e9);
        } else if((l.cnt==0 || l.maxv<root->val) && (r.cnt==0 || r.minv>root->val)) {
            int sum=l.cnt+r.cnt+1;
            ans=max(ans, sum);
            return info(sum, min(l.minv, root->val), max(r.maxv, root->val));
        } else {
            return info(-1, 1e9, -1e9);
        }
    }
};
