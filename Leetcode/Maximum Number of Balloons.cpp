class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> cnt;

        for(int i=0;i<text.length();++i) {
            cnt[text[i]]++;
        }
        
        return min({cnt['b'], cnt['a'], cnt['l']/2, cnt['o']/2, cnt['n']});
    }
};
