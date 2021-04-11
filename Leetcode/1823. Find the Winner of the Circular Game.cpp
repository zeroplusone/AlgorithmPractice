class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> que;
        for(int i=1;i<=n;++i) {
            que.push(i);
        }
        
        while(que.size()>1) {
            for(int i=1;i<=k;++i) {
                int now = que.front();
                que.pop();
                if(i!=k) {
                    que.push(now);
                }
            }
        }
        return que.front();
    }
};
