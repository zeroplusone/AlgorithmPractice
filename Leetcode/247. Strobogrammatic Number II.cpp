class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        if(n==1) {
            return vector<string>{"0", "1", "8"};
        } else if(n==2) {
            return vector<string>{"11", "69", "96", "88"};
        }
        
        vector<string> last=findStrobogrammaticInner(n-2);
        vector<string> two=vector<string>{"11", "69", "96", "88"};
        vector<string> ans;
        for(int i=0;i<last.size();++i) {
            for(int j=0;j<4;++j) {
                ans.push_back(two[j][0]+last[i]+two[j][1]);
            }
        }
        return ans;
    }
    
    vector<string> findStrobogrammaticInner(int n) {
        if(n==1) {
            return vector<string>{"0", "1", "8"};
        } else if(n==2) {
            return vector<string>{"00", "11", "69", "96", "88"};
        }
        
        vector<string> last=findStrobogrammaticInner(n-2);
        vector<string> two=vector<string>{"00", "11", "69", "96", "88"};
        vector<string> ans;
        for(int i=0;i<last.size();++i) {
            for(int j=0;j<5;++j) {
                ans.push_back(two[j][0]+last[i]+two[j][1]);
            }
        }
        return ans;
    }
};
