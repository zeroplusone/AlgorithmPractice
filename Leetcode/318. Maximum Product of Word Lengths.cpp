class Solution {
public:
    
    int maxProduct(vector<string>& words) {
        int ans=0;
        vector<int> bitmap(words.size(), 0);
        for(int i=0;i<words.size();++i) {
            for(int j=0;j<words[i].size();++j) {
                bitmap[i] |= 1<<(words[i][j]-'a');
            }
        }

        for(int i=0;i<words.size();++i) {
            for(int j=i+1;j<words.size();++j) {
                if((bitmap[i]&bitmap[j])==0) {
                    int product = words[i].length()*words[j].length();
                    ans = max(ans, product);
                }
            }
        }
        return ans;
    }
};
