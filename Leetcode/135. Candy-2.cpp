class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int ans=1;
        int oldslope=0, newslope, up=0, down=0;
        for(int i=1;i<n;++i) {
            if(ratings[i]>ratings[i-1]) {
                newslope=1;
            } else if(ratings[i]<ratings[i-1]) {
                newslope=-1;
            } else {
                newslope=0;
            }
            
            if( (oldslope<0 && newslope>=0) || (oldslope>0 && newslope==0)) {
                ans+=up*(up+1)/2 + down*(down+1)/2 + max(up, down);
                up=0;
                down=0;
            }
            
            if(newslope>0) {
                up++;
            } else if(newslope<0) {
                down++;
            } else {
                ans++;
            }
            
            oldslope=newslope;
        }
        ans+=up*(up+1)/2 + down*(down+1)/2 + max(up, down);
        return ans;
    }
};
