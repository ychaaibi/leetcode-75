/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long left=1, right=(long long)n + 1;

        while ( left < right )
        {
            long long md = ( right - left ) / 2 + left;

            if ( !guess(md) )
                return ( md );
            else if ( guess(md) == 1 )
                left = md + 1;
            else
                right = md;
        }
        return (-1);
    }
};