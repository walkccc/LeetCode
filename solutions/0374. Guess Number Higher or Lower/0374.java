/**
 * Forward declaration of guess API.
 * (The problem description is not clear, so I translate it into follows.)
 *
 * @param traget num
 *        guess num
 *
 * @return -1 if guess num >  target num
 *          0 if guess num == target num
 *          1 if guess num <  target num
 */

public class Solution extends GuessGame {
  public int guessNumber(int n) {
    int l = 1;
    int r = n;

    // find the first guess num that >= target num
    while (l < r) {
      final int m = l + (r - l) / 2;
      if (guess(m) <= 0) // -1, 0
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
}
