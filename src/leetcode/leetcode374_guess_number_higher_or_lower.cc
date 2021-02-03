// https://leetcode-cn.com/problems/guess-number-higher-or-lower/
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
  int guessNumber(int n)
  {
    int low = 1, high = n;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      int temp = guess(mid);
      if (temp == 1)
      {
        low = mid + 1;
      }
      else if (temp == -1)
      {
        high = mid - 1;
      }
      else
      {
        return mid;
      }
    }

    return -1;
  }
};
