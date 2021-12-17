class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m=arrays.size();
        map<int, unordered_set<int>, greater<int>> maxm;
        map<int, unordered_set<int>> minm;

        for(int i=0;i<m;++i) {
            minm[arrays[i][0]].insert(i);
            maxm[arrays[i][arrays[i].size()-1]].insert(i);
        }
        
        auto maxi=maxm.begin();
        auto mini=minm.begin();
        

        int ans=0;
        if(maxi->second.size()==1 && mini->second.size()==1 && *(maxi->second.begin()) == *(mini->second.begin())) {
            maxi++;
            mini++;
            ans=max(ans, abs(mini->first-maxm.begin()->first));
            ans=max(ans, abs(minm.begin()->first-maxi->first));
        } else {
            ans=abs(mini->first-maxi->first);
        }
        
        return ans;
    }
};
