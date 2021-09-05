class Solution {
public:
    
    static bool comparator(vector<int>& v1, vector<int>& v2) {
        return v1[0]==v2[0]?v1[1]>v2[1]:v1[0]<v2[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int ans=0;
        int n=properties.size();
        sort(properties.begin(), properties.end(), comparator);
        
        int maxv=properties[n-1][1];
        for(int i=n-2;i>=0;i--) {
            if(properties[i][1]<maxv) {
                ans++;
            }
            maxv=max(maxv, properties[i][1]);
        }
        
        return ans;
    }
};
