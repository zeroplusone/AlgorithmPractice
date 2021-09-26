class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n=board.size();
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                if(board[0][0]^board[i][0]^board[0][j]^board[i][j]) {
                    return -1;
                }
            }
        }
        
        int rsum=0, csum=0, rswap=0, cswap=0;
        for(int i=0;i<n;++i) {
            rsum+=board[0][i];
            csum+=board[i][0];
            rswap+=board[i][0]==i%2;
            cswap+=board[0][i]==i%2;
        }
        
        if(rsum!=n/2 && rsum!=(n+1)/2) {
            return -1;
        }
        
        if(csum!=n/2 && csum!=(n+1)/2) {
            return -1;
        }

        if(n%2==0) {
            rswap=min(n-rswap, rswap);
            cswap=min(n-cswap, cswap);
        } else {
            rswap=rswap%2?n-rswap:rswap;
            cswap=cswap%2?n-cswap:cswap;
        }
        return (rswap+cswap)/2;
    }
};
