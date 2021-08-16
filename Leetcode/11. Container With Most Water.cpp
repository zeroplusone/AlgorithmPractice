class Solution {
public:
    int maxArea(vector<int>& height) {
        int pre=0, post=height.size()-1;
        int ans=0;
        while(pre<post) {
            int now=min(height[post], height[pre]);
            ans=max(ans, (post-pre)*now);
            
            if(height[post]<height[pre]) {
                post--;
            } else {
                pre++;
            }
        }
        return ans;
    }
};
