class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size()-1;
        int inf=1e6;
        vector<int> last {obstacles[0]==1?inf:1, 0, obstacles[0]==3?inf:1};
        vector<int> now(3);
        
        for(int i=1;i<obstacles.size();++i){
            for(int j=0;j<3;++j) {
                if(obstacles[i]-1==j) {
                    now[j]=inf;
                } else {
                    now[j] = last[j];
                }
            }
            
            for(int j=0;j<3;++j) {
                if(obstacles[i]-1!=j) {
                    int other1=(j+1)%3;
                    int other2=(j+2)%3;
                    now[j] = min(now[j], min(now[other1]+1, now[other2]+1));
                }
            }
            
            last = now;
        } 
        
        return min(last[0], min(last[1], last[2]));
    }
};
