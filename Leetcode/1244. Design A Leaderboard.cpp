class Leaderboard {
public:
    Leaderboard() {

    }
    
    void addScore(int playerId, int score) {
        if(m.count(playerId)!=0) {
            auto it=lower_bound(scores.begin(), scores.end(), m[playerId]);
            *(it)=m[playerId]+score;
        } else {
            scores.push_back(score);
        }
        m[playerId]=m[playerId]+score;
        sort(scores.begin(), scores.end());
    }
    
    int top(int K) {
        int ans=0;
        int end=scores.size()-1;
        for(int i=0;i<K;++i) {
            ans+=scores[end-i];
        }
        return ans;
    }
    
    void reset(int playerId) {
        if(m.count(playerId)!=0) {
            auto it=lower_bound(scores.begin(), scores.end(), m[playerId]);
            *(it)=0;
        } else {
            scores.push_back(0);
        }
        m[playerId]=0;
        sort(scores.begin(), scores.end());
    }
    
    unordered_map<int, int> m;
    vector<int> scores;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
