class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) {
            return {};
        }
        
        vector<string> ans {""};
        for(auto digit:digits) {
            int num=digit-'0';
            int st = (num-2)*3 + (num>7?1:0);
            int len = num==7 || num==9?4:3;
            int size=ans.size();
            for(int i=0;i<size;++i) {
                string now=ans[0];
                ans.erase(ans.begin());
                for(int j=0;j<len;++j) {
                    char ch = 'a'+st+j;
                    ans.push_back(now+ch);
                }
            }
        }
        return ans;
    }

};
