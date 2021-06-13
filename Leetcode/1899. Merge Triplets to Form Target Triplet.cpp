class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x=0, y=0, z=0;
        for(int i=0;i<triplets.size();++i) {
            if(triplets[i][0]<=target[0] && triplets[i][1]<=target[1] && triplets[i][2]<=target[2]) {
                x=max(x, triplets[i][0]);
                y=max(y, triplets[i][1]);
                z=max(z, triplets[i][2]);
            }
        }
        return x==target[0] && y==target[1] && z==target[2];
    }
};
