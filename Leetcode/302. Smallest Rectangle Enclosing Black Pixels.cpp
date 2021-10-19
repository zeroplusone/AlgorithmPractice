class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int minx=x, maxx=x;
        int miny=y, maxy=y;
        vector<vector<bool>> v(image.size(), vector<bool>(image[0].size(), false));
        DFS(x, y, image, minx, maxx, miny, maxy, v);
        
        return (maxx-minx+1)*(maxy-miny+1);
    }
    
    vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void DFS(int x, int y, vector<vector<char>>& image, int& minx, int& maxx, int& miny, int& maxy, vector<vector<bool>>& v) {
        minx=min(minx, x);
        maxx=max(maxx, x);
        miny=min(miny, y);
        maxy=max(maxy, y);

        v[x][y]=true;
        for(int i=0;i<4;++i) {
            int newx=x+dir[i][0];
            int newy=y+dir[i][1];
            
            if(newx>=0 && newx<image.size() && newy>=0 && newy<image[0].size() && image[newx][newy]=='1' && !v[newx][newy]) {
                DFS(newx, newy, image, minx, maxx, miny, maxy, v);
            }
        }
    }
    
};
