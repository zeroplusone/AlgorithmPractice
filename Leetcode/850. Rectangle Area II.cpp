class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        set<int> sx, sy;
        for(int i=0;i<rectangles.size();++i) {
            sx.insert(rectangles[i][0]);
            sx.insert(rectangles[i][2]);
            sy.insert(rectangles[i][1]);
            sy.insert(rectangles[i][3]);
        }
        vector<long long int> vx(sx.begin(), sx.end());
        vector<long long int> vy(sy.begin(), sy.end());
        unordered_map<int, int> mx, my;


        for(int i=0;i<vx.size();++i) {
            mx[vx[i]]=i;
        }
        
        for(int i=0;i<vy.size();++i) {
            my[vy[i]]=i;
        }
        
        vector<vector<bool>> v(sx.size(), vector<bool>(sy.size(), false));
        
        long long int ans=0;
        long long int mod=1e9+7;
        for(int i=0;i<rectangles.size();++i) {
            int x1=rectangles[i][0], y1=rectangles[i][1], x2=rectangles[i][2], y2=rectangles[i][3];
            for(int xi=mx[x1];xi<mx[x2];++xi) {
                for(int yi=my[y1];yi<my[y2];++yi) {
                    if(!v[xi][yi]) {
                        ans= (ans+(vx[xi+1]-vx[xi])*(vy[yi+1]-vy[yi]))%mod;
                        v[xi][yi]=true;
                    }
                }
            }
        }
        
        return ans;
    }
    

};
