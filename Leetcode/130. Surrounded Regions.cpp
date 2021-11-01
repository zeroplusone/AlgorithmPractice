class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        
        for(int i=1;i<m-1;++i) {
            if(board[i][0]=='O') {
                DFS(i, 1, board);    
            }
            if(board[i][n-1]=='O') {
                DFS(i, n-2, board);    
            }
        }
        
        for(int i=1;i<n-1;++i) {
            if(board[0][i]=='O') {
                DFS(1, i, board);    
            }
            if(board[m-1][i]=='O') {
                DFS(m-2, i, board);    
            }
        }
        
        for(int i=1;i<m-1;++i) {
            for(int j=1;j<n-1;++j) {
                if(board[i][j]=='F') {
                    board[i][j]='O';       
                } else if(board[i][j]=='O') {
                    board[i][j]='X';
                }
            }
        }
    }
    
    vector<vector<int>> dir={{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    void DFS(int x, int y, vector<vector<char>>& b) {
        if(x<=0 || y<=0 || x>=b.size()-1 || y>=b[0].size()-1 || b[x][y]!='O') {
            return;
        }
        b[x][y]='F';
        for(int i=0;i<4;++i) {
            int newx=x+dir[i][0];
            int newy=y+dir[i][1];
            
            if(b[newx][newy]=='O') {
                DFS(newx, newy, b);
            }
        }
    }
};
