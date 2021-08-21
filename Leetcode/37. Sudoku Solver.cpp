class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> row(9, 0);
        vector<int> col(9, 0);
        vector<int> grid(9, 0);
        for(int i=0;i<9;++i) {
            for(int j=0;j<9;++j) {
                if(board[i][j]!='.') {
                    int mask=1<<(board[i][j]-'0'-1);
                    row[i]|=mask;
                    col[j]|=mask;
                    grid[(i/3)*3+(j/3)]|=mask;
                }
            }
        }
        backtracking(board, row, col, grid);
    }
    
    bool backtracking(vector<vector<char>>& board, vector<int>& row, vector<int>& col, vector<int>& grid) {
        int complete=(1<<9)-1;
        int index=0;
        for(index=0;index<9;++index) {
            if(row[index]!=complete || col[index]!=complete || grid[index]!=complete) {
                break;
            }
        }

        if(index==9) {
            return true;
        }
        
        for(int i=0;i<9;++i) {
            for(int j=0;j<9;++j) {
                if(board[i][j]=='.') {
                    int now=row[i]|col[j]|grid[(i/3)*3+(j/3)];
                    for(int k=0;k<9;++k) {
                        int mask=1<<k;
                        if((now&mask)==0) {
                            row[i]|=mask;
                            col[j]|=mask;
                            grid[(i/3)*3+(j/3)]|=mask;
                            board[i][j]='0'+(k+1);
                            if(backtracking(board, row, col, grid)) {
                                return true;
                            }
                            row[i]&=~mask;
                            col[j]&=~mask;
                            grid[(i/3)*3+(j/3)]&=~mask;
                            board[i][j]='.';
                        }
                    }
                    if(board[i][j]=='.') {
                        return false;
                    }
                }    
            }
        }
        return false;
    }
};
