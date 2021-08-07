class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        char opc=color=='B'?'W':'B';
        int x, y;
        // down
        x=rMove+1;
        while(x<8 && board[x][cMove]==opc) {
            x++;
        }
        
        if(x!=rMove+1 && x<8 && board[x][cMove]==color) {
            return true;
        }
        
        // up
        x=rMove-1;
        while(x>=0 && board[x][cMove]==opc) {
            x--;
        }
        
        if(x!=rMove-1 && x>=0 && board[x][cMove]==color) {
            return true;
        }
        
        // right
        y=cMove+1;
        while(y<8 && board[rMove][y]==opc) {
            y++;
        }
        
        if(y!=cMove+1 && y<8 && board[rMove][y]==color) {
            return true;
        }
        
        // left
        y=cMove-1;
        while(y>=0 && board[rMove][y]==opc) {
            y--;
        }
        
        if(y!=cMove-1 && y>=0 && board[rMove][y]==color) {
            return true;
        }
        
        // right down
        x=rMove+1;  y=cMove+1;
        while(x<8 && y<8 && board[x][y]==opc) {
            x++; y++;
        }
        
        if(x!=rMove+1 && x<8 && y<8 && board[x][y]==color) {
            return true;
        }
        
        // left up
        x=rMove-1;  y=cMove-1;
        while(x>=0 && y>=0 && board[x][y]==opc) {
            x--; y--;
        }
        
        if(x!=rMove-1 && x>=0 && y>=0 && board[x][y]==color) {
            return true;
        }
        
        // right up
        x=rMove-1;  y=cMove+1;
        while(x>=0 && y<8 && board[x][y]==opc) {
            x--; y++;
        }
        
        if(x!=rMove-1 && x>=0 && y<8 && board[x][y]==color) {
            return true;
        }
        
        // left down
        x=rMove+1;  y=cMove-1;
        while(x<8 && y>=0 && board[x][y]==opc) {
            x++; y--;
        }
        
        if(x!=rMove+1 && x<8 && y>=0 && board[x][y]==color) {
            return true;
        }
        
        return false;
    }
};
