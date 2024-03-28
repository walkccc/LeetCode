class Solution {
  public int monotoneIncreasingDigits(int n) {
    char[] s = String.valueOf(n).toCharArray();
    final int n = s.length;
    int k = n; // s[k..n) -> '9'

    for (int i = n - 1; i > 0; --i)
      if (s[i] < s[i - 1]) {
        --s[i - 1];
        k = i;
      }

    for (int i = k; i < n; ++i)
      s[i] = '9';

    return Integer.parseInt(new String(s));
  }
}
