class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        
        int sum=0;
        for(int i=0;i<piles.size();++i) {
            sum+=piles[i];
            pq.push(piles[i]);
        }
        
        int remove=0;
        for(int i=0;i<k;++i) {
            int now=pq.top();
            pq.pop();
            remove=now/2;
            sum-=remove;
            pq.push(now-remove);
        }
        return sum;
    }
};
