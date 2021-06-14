class Solution {
public:
    static bool comparator(vector<int> a, vector<int> b) {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comparator);
        
        int ans=0;
        for(int i=0; i<boxTypes.size();++i) {
            if(truckSize>0) {
                ans+=min(truckSize, boxTypes[i][0])*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
            } else {
                break;
            }
        }
        return ans;
    }
};
