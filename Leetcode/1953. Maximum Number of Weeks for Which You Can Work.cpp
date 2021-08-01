class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long int sum=0, maxv=0;
        for(int i=0;i<milestones.size();++i) {
            sum+=milestones[i];
            if(milestones[i]>maxv) {
                maxv=milestones[i];
            }
        }
        
        if(sum-maxv < maxv) {
            return 2*(sum-maxv)+1;
        } else {
            return sum;
        }
    }
};
