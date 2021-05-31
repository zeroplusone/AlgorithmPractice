class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans(searchWord.size(), vector<string>(0));
        vector<bool> isSubstr(products.size(), true);
        int cur=0;
        string search="";
        for(int i=0;i<searchWord.size();++i) {
            search+=searchWord[i];
            for(int j=cur;j<products.size()&&ans[i].size()<3;++j) {
                if(isSubstr[j] && products[j].length()>=i+1  && products[j].substr(0,i+1)==search) {
                    if(ans[i].size()==0) {
                        cur=j;
                    }
                    ans[i].push_back(products[j]);
                } else {
                    isSubstr[j]=false;
                }
            }
            if(ans[i].size()==0) {
                break;
            }
            
        }
        return ans;
        
    }
};
