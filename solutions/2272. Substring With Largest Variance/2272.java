class Solution {
  public int largestVariance(String s) {
    int ans = 0;

    for (char a = 'a'; a <= 'z'; ++a)
      for (char b = 'a'; b <= 'z'; ++b)
        if (a != b)
          ans = Math.max(ans, kadane(s, a, b));

    return ans;
  }

  // a := the letter with the higher frequency
  // b := the letter with the lower frequency
  private int kadane(final String s, char a, char b) {
    int ans = 0;
    int countA = 0;
    int countB = 0;
    boolean canExtendPrevB = false;

    for (final char c : s.toCharArray()) {
      if (c != a && c != b)
        continue;
      if (c == a)
        ++countA;
      else
        ++countB;
      if (countB > 0) {
        // An interval should contain at least one b.
        ans = Math.max(ans, countA - countB);
      } else if (countB == 0 && canExtendPrevB) {
        // edge case: consider the previous b
        ans = Math.max(ans, countA - 1);
      }
      // Reset if the number of b > the number of a.
      if (countB > countA) {
        countA = 0;
        countB = 0;
        canExtendPrevB = true;
      }
    }

    return ans;
  }
}
