class Solution {
  public boolean hasSameDigits(String s) {
    final int n = s.length();
    int num1 = 0;
    int num2 = 0;

    for (int i = 0; i + 1 < n; ++i) {
      final int coefficient = nCMOD10(n - 2, i);
      num1 += (coefficient * (s.charAt(i) - '0')) % 10;
      num1 %= 10;
      num2 += (coefficient * (s.charAt(i + 1) - '0')) % 10;
      num2 %= 10;
    }

    return num1 == num2;
  }

  // Returns (n, k) % 10.
  private int nCMOD10(int n, int k) {
    final int mod2 = lucasTheorem(n, k, 2);
    final int mod5 = lucasTheorem(n, k, 5);
    int[][] lookup = {
        {0, 6, 2, 8, 4}, // mod2 == 0
        {5, 1, 7, 3, 9}  // mod2 == 1
    };
    return lookup[mod2][mod5];
  }

  // Returns (n, k) % prime.
  private int lucasTheorem(int n, int k, int prime) {
    int res = 1;
    while (n > 0 || k > 0) {
      final int nMod = n % prime;
      final int MOD = k % prime;
      res *= nCk(nMod, MOD);
      res %= prime;
      n /= prime;
      k /= prime;
    }
    return res;
  }

  // Returns (n, k).
  private int nCk(int n, int k) {
    int res = 1;
    for (int i = 0; i < k; ++i) {
      res *= (n - i);
      res /= (i + 1);
    }
    return res;
  }
}
