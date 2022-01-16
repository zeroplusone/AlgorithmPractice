class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans=0;
        int left=0;
        while(left<seats.size() && seats[left]==0) {
            left++;
        }
        ans=max(ans, left);
        
        int right=0;
        while(seats.size()-1-right>=0 && seats[seats.size()-1-right]==0) {
            right++;
        }
        ans=max(ans, right);
        right=seats.size()-1-right;
        
        int mid=0;
        for(int i=left;i<=right;++i) {
            if(seats[i]==1) {
                ans=max(ans, (mid+1)/2);
                mid=0;
            } else {
                mid++;
            }
        }
        return ans;
    }
};

