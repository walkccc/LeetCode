class Solution {
  public boolean sumGame(String num) {
    final int n = num.length();
    double ans = 0.0;

    for (int i = 0; i < n / 2; ++i)
      ans += getExpectation(num.charAt(i));

    for (int i = n / 2; i < n; ++i)
      ans -= getExpectation(num.charAt(i));

    return ans != 0.0;
  }

  private double getExpectation(char c) {
    return c == '?' ? 4.5 : c - '0';
  }
}
