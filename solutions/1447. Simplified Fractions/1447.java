class Solution {
  public List<String> simplifiedFractions(int n) {
    List<String> ans = new ArrayList<>();
    for (int denominator = 2; denominator <= n; ++denominator)
      for (int numerator = 1; numerator < denominator; ++numerator)
        if (gcd(denominator, numerator) == 1)
          ans.add(String.valueOf(numerator) + "/" + String.valueOf(denominator));
    return ans;
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
