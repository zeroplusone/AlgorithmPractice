class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end(), [](vector<int> p1, vector<int> p2) {
            return p1[0]==p2[0]?p1[1]<p2[1]:p1[0]<p2[0];
        });
        
        vector<vector<int>> ans;
        for(int i=0;i<trees.size();++i) {
            // cout<<trees[i][0]<<" "<<trees[i][1]<<endl;
            while(ans.size()>=2 && cross(ans[ans.size()-2], ans[ans.size()-1], trees[i])<0) {
                ans.pop_back();
            }
            ans.push_back(trees[i]);
        }
        if(ans.size()!=trees.size()) {
            int k=ans.size()+1;
            for(int i=trees.size()-2;i>=0;i--) {
                while(ans.size()>=k && cross(ans[ans.size()-2], ans[ans.size()-1], trees[i])<0) {
                    ans.pop_back();
                }
                ans.push_back(trees[i]);
            }
            ans.pop_back();    
        }
        
        return ans;
    }
    
    int cross(vector<int> O, vector<int> A, vector<int> B) {
        return (A[0]-O[0])*(B[1]-O[1])-(A[1]-O[1])*(B[0]-O[0]);
    }
};
