class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n=asteroids.size();

        for(int i=0;i<n;++i) {
            if(asteroids[i]>0) {
                ans.push_back(asteroids[i]);
            } else {
                bool win=true;
                while(ans.size()>0) {
                    int last=ans[ans.size()-1];
                    if(last<0) {
                        win=true;
                        break;
                    } else if(last==abs(asteroids[i])) {
                        ans.pop_back();
                        win=false;
                        break;
                    } else if(last<abs(asteroids[i])){
                        ans.pop_back();
                        win=true;
                    } else {
                        win=false;
                        break;
                    }
                }
                if(win) {
                    ans.push_back(asteroids[i]);
                }
            }
        }

        return ans;
    }
};
