class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int maxv=releaseTimes[0];
        char ans=keysPressed[0];
        for(int i=1;i<releaseTimes.size();++i) {
            int diff=releaseTimes[i]-releaseTimes[i-1];
            if(diff>maxv) {
                maxv=diff;
                ans=keysPressed[i];
            }else if(diff==maxv && keysPressed[i]>ans ) {
                ans=keysPressed[i];
            }
        }
        return ans;
    }
};
