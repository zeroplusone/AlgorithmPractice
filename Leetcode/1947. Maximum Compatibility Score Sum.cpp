class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m=students.size();
        int n=students[0].size();
        vector<vector<int>> score(m, vector<int>(m, 0));

        for(int i=0;i<m;++i) {
            for(int j=0;j<m;++j) {
                for(int k=0;k<n;++k) {
                    score[i][j]+=students[i][k]==mentors[j][k]?1:0;
                }
            }
        }
        int ans=0;
        vector<bool> visit(m, false);
        DFS(0, m, n, 0, visit, score, ans);
        return ans;
    }
    
    void DFS(int now, int m, int n, int sum, vector<bool>& visit, vector<vector<int>>& score, int& ans) {
        if(now==m) {
            ans=max(ans, sum);
            return;
        }

        for(int i=0;i<m;++i) {
            if(!visit[i]) {
                visit[i]=true;
                DFS(now+1, m, n, sum+score[now][i], visit, score, ans);
                visit[i]=false;
            }
        }
    }
};
