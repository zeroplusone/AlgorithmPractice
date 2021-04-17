//Given a matrix and a target, return the number of non-empty submatrices that s
//um to target. 
//
// A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x 
//<= x2 and y1 <= y <= y2. 
//
// Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if th
//ey have some coordinate that is different: for example, if x1 != x1'. 
//
// 
// Example 1: 
//
// 
//Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
//Output: 4
//Explanation: The four 1x1 submatrices that only contain 0.
// 
//
// Example 2: 
//
// 
//Input: matrix = [[1,-1],[-1,1]], target = 0
//Output: 5
//Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2
//x2 submatrix.
// 
//
// Example 3: 
//
// 
//Input: matrix = [[904]], target = 0
//Output: 0
// 
//
// 
// Constraints: 
//
// 
// 1 <= matrix.length <= 100 
// 1 <= matrix[0].length <= 100 
// -1000 <= matrix[i] <= 1000 
// -10^8 <= target <= 10^8 
// 
// Related Topics Array Dynamic Programming Sliding Window 
// 👍 936 👎 31


#include <bits/stdc++.h>

using namespace std;

#define PR pair<int,int>
#define pb push_back

#define mp make_pair

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
        int M = matrix.size();
        int N = matrix[0].size();
        vector<vector<long long>> dp(M + 1, vector<long long>(N + 1, 0));
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                dp[i][j] = matrix[i-1][j-1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }
        }


        int ans = 0;
        for (int xlen = 1; xlen <= M; ++xlen) {
            for (int ylen = 1; ylen <= N; ++ylen) {
                for (int x = 0; x + xlen <= M; ++x) {
                    for (int y = 0; y + ylen <= N; ++y) {
                        if (dp[x+xlen][y+ylen] - dp[x][y+ylen] - dp[x+xlen][y] + dp[x][y] == target) {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<vector<int>> matrix = {{1, -1},
                                  {-1, 1}};
    int target = 0;
    cout << s.numSubmatrixSumTarget(matrix, target) << endl;
    return 0;
}