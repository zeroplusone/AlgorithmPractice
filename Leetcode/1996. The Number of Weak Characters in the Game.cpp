class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int ans=0;
        int n=properties.size();
        sort(properties.begin(), properties.end());
        
        int lastx=properties[n-1][0];
        int maxv=properties[n-1][1];
        unordered_map<int,int> maxmap;
        for(int i=n-2;i>=0;) {
            while(i>=0 && properties[i][0]==lastx) {
                maxv=max(maxv, properties[i][1]);
                i--;
            }
            if(i<0) {
                break;
            }
            maxmap[properties[i][0]]=maxv;
            lastx=properties[i][0];
        }
        
        for(int i=0;i<n;++i) {
            if(maxmap[properties[i][0]]>properties[i][1]) {
                ans++;
            }
        }
        return ans;
    }
};
