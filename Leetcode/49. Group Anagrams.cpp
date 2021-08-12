class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> m;
        for(int i=0;i<strs.size();++i) {
            string tmp=strs[i];
            sort(strs[i].begin(), strs[i].end());
            if(m.count(strs[i])==0) {
                m[strs[i]]=vector<string>{tmp};
            } else {
                m[strs[i]].push_back(tmp);    
            }
            
        }
        
        vector<vector<string>> ans(m.size());
        auto it=m.begin();
        for(int i=0;i<m.size();++i, it++) {
            ans[i]=it->second;
        }
        return ans;
    }
};
