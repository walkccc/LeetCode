class Solution {
  public int commonFactors(int a, int b) {
    int ans = 1;
    final int gcd = gcd(a, b);
    for (int i = 2; i <= gcd; ++i)
      if (a % i == 0 && b % i == 0)
        ++ans;
    return ans;
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
