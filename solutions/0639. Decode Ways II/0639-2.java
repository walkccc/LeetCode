class Solution {
  public int numDecodings(String s) {
    final int kMod = 1_000_000_007;
    final int n = s.length();
    long prev2 = 1;
    long prev1 = count(s.charAt(n - 1));

    for (int i = n - 2; i >= 0; --i) {
      long dp = count(s.charAt(i), s.charAt(i + 1)) * prev2 + count(s.charAt(i)) * prev1;
      dp %= kMod;
      prev2 = prev1;
      prev1 = dp;
    }

    return (int) prev1;
  }

  private int count(char c) {
    if (c == '*')
      return 9;
    return c == '0' ? 0 : 1;
  }

  private int count(char c1, char c2) {
    if (c1 == '*' && c2 == '*')
      return 15; // c1c2: [11-19, 21-26]
    if (c1 == '*') {
      if ('0' <= c2 && c2 <= '6')
        return 2; // c1: [1-2]
      else
        return 1; // c1: [1]
    }
    if (c2 == '*') {
      if (c1 == '1')
        return 9; // c2: [1-9]
      if (c1 == '2')
        return 6; // c2: [1-6]
      return 0;
    }
    return (c1 == '1' || (c1 == '2' && c2 <= '6')) ? 1 : 0;
  }
}
