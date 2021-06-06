class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        bool is_rotate=compare(mat, target);

        for(int i=0;i<3&&!is_rotate;++i) {
            rotate(mat);
            is_rotate=compare(mat, target);
        }
        return is_rotate;
    }
    
    bool compare(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0;i<mat.size();++i) {
            for(int j=0;j<mat[0].size();++j) {
                if(mat[i][j]!=target[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    void rotate(vector<vector<int>>& mat) {
        for(int i=0;i<mat.size();++i) {
            for(int j=0;j<i;++j) {
                int tmp=mat[i][j];
                mat[i][j]=mat[j][i];
                mat[j][i]=tmp;
            }
        }
        for(int i=0;i<mat.size();++i) {
            for(int j=0;j<mat[0].size()/2;++j) {
                int tmp=mat[i][j];
                mat[i][j]=mat[i][mat.size()-j-1];
                mat[i][mat.size()-j-1]=tmp;
            }
        }
    }
};
