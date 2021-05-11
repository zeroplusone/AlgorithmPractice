class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int begin=0, end=0;
        for(int i=cardPoints.size()-k;i<cardPoints.size();++i) {
            end+=cardPoints[i];
        }
        int ans=end;
        for(int i=0;i<k;++i) {
            begin+=cardPoints[i];
            end-=cardPoints[cardPoints.size()-k+i];
            ans=max(ans, begin+end);
        }
        return ans;
    }
};
