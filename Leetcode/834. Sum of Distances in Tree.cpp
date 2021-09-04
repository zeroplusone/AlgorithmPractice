class Solution {
public:
    
    struct TreeNode {
        int val;
        vector<TreeNode*> children;
        int totalChildren;
        int subTreeSum;
        TreeNode(int val):val(val), totalChildren(0), subTreeSum(0), children(vector<TreeNode*>(0)){};
    };
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n, -1);
        vector<bool> v(n, false);
        unordered_map<int, vector<int>> graph;
        for(int i=0;i<edges.size();++i) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        TreeNode* root=buildTree(0, n, graph, v);
        ans[0]=root->subTreeSum;
        for(int i=0;i<root->children.size();++i) {
            traverse(root, root->children[i], ans, n);    
        }
        return ans;
    }
    
    TreeNode* buildTree(int now, int& n, unordered_map<int, vector<int>>& graph, vector<bool>& v) {
        TreeNode* root=new TreeNode(now);
        v[now]=true;
        int cnt=1;
        int sum=0;
        for(int i=0;i<graph[now].size();++i) {
            if(!v[graph[now][i]]) {
                TreeNode* child=buildTree(graph[now][i], n, graph, v);
                (root->children).push_back(child);
                cnt+=child->totalChildren;
                sum+=child->subTreeSum+child->totalChildren;
            }
        }
        root->totalChildren=cnt;
        root->subTreeSum=sum;
        return root;
    }
    
    void traverse(TreeNode* parent, TreeNode* now, vector<int>& ans, int& n) {
        ans[now->val]=ans[parent->val]-(now->totalChildren)+n-(now->totalChildren);
        for(int i=0;i<now->children.size();++i) {
            traverse(now, now->children[i], ans, n);
        }
    }
    
};
