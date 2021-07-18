class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int last=0;
        int ans=0;
        for(int i=0;i<rungs.size();++i) {
            if(rungs[i]-last > dist) {
                ans+=(rungs[i]-last-1)/dist;
            }
            last=rungs[i];
        }
        return ans;
    }
};
