/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int rows=dim[0];
        int cols=dim[1];
        
        int l=0, r=cols-1;
        while(l<=r) {
            int mid=(l+r+1)/2;
            
            if(canbe(binaryMatrix, rows, mid)) {
                l=mid;
                if(l==r) {
                    break;
                }
            } else {
                r=mid-1;
            }
        }
        
        return r==cols-1?-1:r+1;
    }
    
    bool canbe(BinaryMatrix &binaryMatrix, int& rows, int& c) {
        for(int r=0;r<rows;++r) {
            if(binaryMatrix.get(r, c)==1) {
                return false;
            }
        }
        return true;
    }
};
