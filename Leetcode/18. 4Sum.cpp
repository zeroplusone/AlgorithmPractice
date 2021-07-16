class Solution {
public:

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        unordered_set<string> ans;
        int n=nums.size();
        if(n<4) {
            return vector<vector<int>>(0);
        }

        for(int i=1;i<n;++i) {
            for(int j=0;j<i;++j) {
                long long int base=nums[i]+nums[j], sum;
                int l=i+1, r=n-1;
                while(l<r) {
                    sum=base+nums[l]+nums[r];
                    if(sum<target) {
                        l++;    
                    } else if(sum>target) {
                        r--;
                    } else {
                        ans.insert(toString(vector<int>{nums[j], nums[i], nums[l], nums[r]}));
                        l++;
                        r--;
                    }
                }
            }
        }
        
        vector<vector<int>> ret(ans.size());
        auto it=ans.begin();
        for(int i=0;i<ans.size();++i, it++) {
            ret[i]=toVector(*it);
        }
        return ret;
    }
    
    string toString(vector<int> v) {
        string ret="";
        for(int i=0;i<v.size();++i) {
            ret+=to_string(v[i])+"#";
        }
        return ret;
    }
    
    vector<int> toVector(string s) {
        vector<int> ret;
        size_t pos = 0;
        string token;
        while ((pos = s.find("#")) != string::npos) {
            token = s.substr(0, pos);
            ret.push_back(stoi(token));
            s.erase(0, pos + 1);
        }
        return ret;
    }
};
