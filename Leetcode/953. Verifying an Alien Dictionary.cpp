class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<char> order_index(26);
        
        for(int i=0;i<order.length();++i) {
            order_index[order[i]-'a'] = 'a'+i;
        }
        
        string last="", now;
        for(auto word:words) {
            now="";
            for(auto w:word) {
                now+=order_index[w-'a'];
            }

            if(strcmp(last.c_str(), now.c_str())>0) {
                return false;
            }
            last=now;
        }
        return true;
    }
};
