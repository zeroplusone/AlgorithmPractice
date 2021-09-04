class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size()!=sentence2.size()) {
            return false;
        }
        
        unordered_map<string, string> p;
        for(int i=0;i<similarPairs.size();++i) {
            string px=findp(similarPairs[i][0], p);
            string py=findp(similarPairs[i][1], p);
            p[px]=py;
        }
        
        for(int i=0;i<sentence1.size();++i) {
            string px=findp(sentence1[i], p);
            string py=findp(sentence2[i], p);
            if(sentence1[i]!=sentence2[i] && px!=py) {
                return false;
            } 
        }
        return true;
    }
    
    string findp(string now, unordered_map<string, string>& p) {
        if(p.count(now)==0 || p[now]==now) {
            return now;
        } else {
            p[now]=findp(p[now], p);
            return p[now];
        }
    }
};
