class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        vector<pair<char, int>> cnts=count(s);
        
        int ans=0;
        for(int i=0;i<words.size();++i) {
            vector<pair<char, int>> wcnts=count(words[i]);
            if(cnts.size()!=wcnts.size()) {
                continue;
            }
            int j=0;
            for(;j<cnts.size();++j) {
                if(cnts[j].first!=wcnts[j].first) {
                    break;
                }
                
                if(cnts[j].second<wcnts[j].second || (cnts[j].second!=wcnts[j].second && cnts[j].second<3)) {
                    break;
                }
            }
            ans+=j==cnts.size()?1:0;
        }
        
        return ans;
        
    }
    
    vector<pair<char,int>> count(string s) {
        vector<pair<char, int>> cnts;
        char last=s[0];
        int cnt=1;
        for(int i=1;i<s.length();++i) {
            if(s[i]==last) {
                cnt++;
            } else {
                cnts.push_back(make_pair(last, cnt));
                last=s[i];
                cnt=1;
            }
        }
        cnts.push_back(make_pair(last, cnt));
        return cnts;
    }
};
