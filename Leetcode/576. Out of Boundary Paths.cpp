class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        long long int ans=0;
        long long int mod=1e9+7;

        unordered_map<int, long long int> que;
        int startIndex=(startRow+1)*(n+2) + startColumn+1;
        que[startIndex]=1;
        vector<int> dir ={+1, -1, n+2, -n-2};
        for(int i=0;i<maxMove;++i) {
            unordered_map<int, long long int> last(que.begin(), que.end());
            que.clear();
            for(auto l:last) {
                for(int j=0;j<4;++j) {
                    int newIndex=l.first+dir[j];
                    int row=newIndex/(n+2);
                    int col=newIndex%(n+2);
                    if(row==0 || row==m+1 || col==0 || col==n+1) {
                        ans=(ans+l.second)%mod;
                    } else {
                        que[newIndex]=(que[newIndex]+l.second)%mod;
                    }
                }
            }
        }

        return ans;
    }
};
