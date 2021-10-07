class Solution {
public:
    vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        
        bool found=false;
        vector<vector<bool>> v(m, vector<bool>(n, false));
        for(int i=0;i<m&&!found;++i) {
            for(int j=0;j<n&&!found;++j) {
                v[i][j]=true;
                found|=DFS(0, i, j, board, word, v);
                v[i][j]=false;
            }
        }
        return found;
    }
    
    bool DFS(int now, int x, int y, vector<vector<char>>& b, string& w, vector<vector<bool>>& v) {
        if(w[now]!=b[x][y]) {
            return false;
        }
        if(now==w.length()-1) {
            return true;
        }
        

        bool found=false;
        for(int i=0;i<4&&!found;++i) {
            int newx=x+dir[i][0];
            int newy=y+dir[i][1];
            if(newx>=0 && newx<b.size() && newy>=0 && newy<b[0].size() && !v[newx][newy]) {
                v[newx][newy]=true;
                found|=DFS(now+1, newx, newy, b, w, v);
                v[newx][newy]=false;
            }
        }
        return found;
    }
};
