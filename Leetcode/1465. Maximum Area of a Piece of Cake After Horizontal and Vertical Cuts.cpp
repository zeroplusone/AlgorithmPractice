class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long long int maxW=0, maxH=0;
        for(int i=0;i<=horizontalCuts.size();++i) {
            long long int diff;
            if(i==0) {
                diff=horizontalCuts[i];
            } else if(i==horizontalCuts.size()) {
                diff=h-horizontalCuts[i-1];
            } else {
                diff=horizontalCuts[i]-horizontalCuts[i-1];
            }
            maxH=max(diff, maxH);
        }
        for(int i=0;i<=verticalCuts.size();++i) {
            long long int diff;
            if(i==0) {
                diff=verticalCuts[i];
            } else if(i==verticalCuts.size()) {
                diff=w-verticalCuts[i-1];
            } else {
                diff=verticalCuts[i]-verticalCuts[i-1];
            }
            maxW=max(diff, maxW);
        }
        long long int mod = 1e9+7;
        long long int ans = maxW*maxH%mod;
        return ans;
    }
};
