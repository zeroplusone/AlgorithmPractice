class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> grid(3, vector<char>(3, ' '));
        for(int i=0;i<moves.size();++i) {
            if(i%2==0) {
                grid[moves[i][0]][moves[i][1]]='X';
            } else {
                grid[moves[i][0]][moves[i][1]]='O';
            }
        }

        for(int i=0;i<3;++i) {
            int row=0, col=0;
            for(int j=0;j<3;++j) {
                row+=grid[i][j]=='X'?1:(grid[i][j]=='O'?-1:0);
                col+=grid[j][i]=='X'?1:(grid[j][i]=='O'?-1:0);
            }
            if(row==3 || col==3) {
                return "A";
            } else if(row==-3 || col==-3) {
                return "B";
            }
        }
        
        int left=0, right=0;
        for(int i=0;i<3;++i) {
            left+=grid[i][i]=='X'?1:(grid[i][i]=='O'?-1:0);
            right+=grid[i][2-i]=='X'?1:(grid[i][2-i]=='O'?-1:0);
        }
        if(left==3 || right==3) {
            return "A";
        } else if(left==-3 || right==-3) {
            return "B";
        } 
        
        if(moves.size()==9) {
            return "Draw";
        }

        return "Pending";
    }
};
