// bitmask solution
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        int maxPick=pow(2, n);
        vector<vector<int>> ans;
        unordered_set<string> exist;

        for(int pick=0;pick<maxPick;++pick) {
            vector<int> subset=vector<int>(0);
            int mask=1;
            for(int i=0;i<nums.size();++i) {
                if(pick&(mask<<i)){
                    subset.push_back(nums[i]);
                }
            }
            string hash=getHash(subset);
            if(exist.count(hash)==0) {
                ans.push_back(subset);
                exist.insert(hash);
            }
        }
        return ans;
    }
    
    string getHash(vector<int> subset) {
        sort(subset.begin(), subset.end());
        string ret="";
        for(int i=0;i<subset.size();++i) {
            ret+=to_string(subset[i]);
        }
        return ret;
    }
};
