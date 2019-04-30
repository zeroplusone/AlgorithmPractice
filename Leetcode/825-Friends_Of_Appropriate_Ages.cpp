/*********************
problem: 825. Friends Of Appropriate Ages
https://leetcode.com/contest/weekly-contest-82/problems/friends-of-appropriate-ages/
**********************/
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans=0;
        int agesum[125];
        for(int i=1;i<121;++i) {
            agesum[i]=0;
        }
        for(int i=ages.size()-1;i>=0;--i){
            agesum[ages[i]]++;
        }
        for(int i=120;i>0;--i){
            if(agesum[i]!=0){
                for(int j=i;j>0;--j){
                    if(agesum[j]!=0){
                        if(j>0.5*i+7){
                            if(i==j)
                                ans+=agesum[i]>1?agesum[i]*(agesum[i]-1):0;
                            else
                                ans+=agesum[j]*agesum[i];
                            // cout<<i<<" "<<j<<" "<<ans<<endl;
                        }
                    }
                }
            }
        }
        return ans;
    }
};