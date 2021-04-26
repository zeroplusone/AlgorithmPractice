class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int ans=0, brick=0, diff;
        priority_queue <int, vector<int>, greater<int> > pq;

        for(int i=1;i<heights.size();++i){
            diff = heights[i]-heights[i-1];
            if(diff>0) {
                pq.push(diff);
                if(pq.size()>ladders) {
                    brick+=pq.top();    
                    pq.pop();
                    if(brick>bricks) {
                        break;
                    }
                } 
            }
            ans=i;
        }
        return ans;
    }
};
