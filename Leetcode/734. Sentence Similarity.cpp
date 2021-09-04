class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size()!=sentence2.size()) {
            return false;
        }
        
        unordered_map<string, unordered_set<string>> pairs;
        for(int i=0;i<similarPairs.size();++i) {
            pairs[similarPairs[i][0]].insert(similarPairs[i][1]);
            pairs[similarPairs[i][1]].insert(similarPairs[i][0]);
        }
        
        for(int i=0;i<sentence1.size();++i) {
            if(sentence1[i]!=sentence2[i] && pairs[sentence1[i]].count(sentence2[i])==0) {
                return false;
            } 
        }
        return true;
        
    }
};
