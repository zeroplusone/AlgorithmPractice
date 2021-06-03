class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxH=max(horizontalCuts[0], h-horizontalCuts[horizontalCuts.size()-1]);
        int maxW=max(verticalCuts[0], w-verticalCuts[verticalCuts.size()-1]);
        for(int i=1;i<horizontalCuts.size();++i) {
            maxH=max(maxH, horizontalCuts[i]-horizontalCuts[i-1]);
        }
        for(int i=1;i<verticalCuts.size();++i) {
            maxW=max(maxW, verticalCuts[i]-verticalCuts[i-1]);
        }
        long long int mod = 1e9+7;
        long long int ans = (long long int)maxW*(long long int)maxH%mod;
        return ans;
    }
};
