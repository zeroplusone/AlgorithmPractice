class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans(0);
        
        for(int i=0,j=0;i<firstList.size()&&j<secondList.size();) {
            int s1=firstList[i][0], e1=firstList[i][1];
            int s2=secondList[j][0], e2=secondList[j][1];

            if(e1<s2) {
                i++;
            } else if(e1==s2) {
                ans.push_back(vector<int>{e1, s2});
                i++;
            } else if(e2<s1) {
                j++;
            } else if(e2==s1) {
                ans.push_back(vector<int>{e2, s1});
                j++;
            } else if(s1<=s2 && e1<=e2) {
                ans.push_back(vector<int>{s2, e1});
                i++;
            } else if(s2<=s1 && e2<=e1) {
                ans.push_back(vector<int>{s1, e2});
                j++;
            } else if(s1<=s2 && e1>=e2) {
                ans.push_back(vector<int>{s2, e2});
                j++;
            } else if(s2<=s1 && e2>=e1) {
                ans.push_back(vector<int>{s1, e1});
                i++;
            } 
            
        }
        return ans;
        
    }
};
