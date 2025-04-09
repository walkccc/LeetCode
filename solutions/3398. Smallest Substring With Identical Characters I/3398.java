class Solution {
  public int minLength(String s, int numOps) {
    int l = 1;
    int r = s.length();

    while (l < r) {
      final int m = (l + r) / 2;
      if (getMinOps(s, m) <= numOps)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  // Returns the minimum number of operations needed to make all groups of
  // identical characters of length k or less.
  private int getMinOps(final String s, int k) {
    if (k == 1) {
      int res = 0;
      for (int i = 0; i < s.length(); ++i)
        if (s.charAt(i) - '0' == i % 2)
          ++res;
      return Math.min(res, s.length() - res);
    }

    int res = 0;
    int runningLen = 1;

    for (int i = 1; i < s.length(); ++i)
      if (s.charAt(i) == s.charAt(i - 1)) {
        ++runningLen;
      } else {
        res += runningLen / (k + 1);
        runningLen = 1;
      }

    return res + runningLen / (k + 1);
  }
}
