class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> v;
        for(int i=0;i<9;++i) {
            v.clear();
            for(int j=0;j<9;++j) {
                if(board[i][j]=='.') {
                    continue;
                } else if(v.count(board[i][j])!=0) {
                    return false;
                } else {
                    v.insert(board[i][j]);
                }
            }
            v.clear();
            for(int j=0;j<9;++j) {
                if(board[j][i]=='.') {
                    continue;
                } else if(v.count(board[j][i])!=0) {
                    return false;
                } else {
                    v.insert(board[j][i]);
                }
            }
            
            v.clear();
            int x=(i/3)*3;
            int y=(i%3)*3;
            for(int j=0;j<3;++j) {
                for(int k=0;k<3;++k) {
                    if(board[x+j][y+k]=='.') {
                        continue;
                    } else if(v.count(board[x+j][y+k])!=0) {
                        return false;
                    } else {
                        v.insert(board[x+j][y+k]);
                    }
                }
            }
        }
        return true;
        
    }
};
