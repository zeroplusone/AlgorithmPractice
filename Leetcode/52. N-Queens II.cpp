class Solution {
public:
    int totalNQueens(int n) {
        string dot="";
        for(int i=0;i<n;++i) {
            dot+=".";
        }
        vector<string> matrix(n, dot);
        vector<bool> row(n, false);
        vector<bool> col(n, false);
        vector<bool> dia1(n*2-1, false);
        vector<bool> dia2(n*2-1, false);
        solve(0, n, matrix, row, col, dia1, dia2);
        return ans;
    }
    
    void solve(int now, int n, vector<string>& matrix, vector<bool> row, vector<bool> col,  vector<bool> dia1, vector<bool> dia2) { 
        if(now==n) {
            ans++;
            return;
        }
        for(int i=0;i<n;++i) {
            if(!row[now] && !col[i] && !dia1[now+i] && !dia2[n-i-1+now]) {
                matrix[now][i]='Q';
                row[now]=true;
                col[i]=true;
                dia1[now+i]=true;
                dia2[n-i-1+now]=true;
                solve(now+1, n, matrix, row, col, dia1, dia2);
                matrix[now][i]='.';
                row[now]=false;
                col[i]=false;
                dia1[now+i]=false;
                dia2[n-i-1+now]=false;
            }
        }
        
    }
    
private:
    int ans;
};
