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
        
        int r=0, c=cols-1;
        for(;r<rows;++r) {
            for(;c>=0;--c) {
                if(binaryMatrix.get(r, c)==0) {
                    break;
                }
            }
        }
        
        return c+1==cols?-1:c+1;
    }
};
