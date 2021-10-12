/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long int l=1, r=n;
        while(l<=r) {
            long long int mid = (l+r+1)/ 2;
            int ret=guess(mid);
            if(ret==0) {
                return mid;
            } else if(ret==-1) {
                r=mid-1;
            } else {
                l=mid+1;
                
            }
        }
        return -1;
    }
};
