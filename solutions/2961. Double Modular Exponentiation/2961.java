class Solution {
  public List<Integer> getGoodIndices(int[][] variables, int target) {
    List<Integer> ans = new ArrayList<>();
    for (int i = 0; i < variables.length; ++i) {
      final int a = variables[i][0];
      final int b = variables[i][1];
      final int c = variables[i][2];
      final int m = variables[i][3];
      if (modPow(modPow(a, b, 10), c, m) == target)
        ans.add(i);
    }
    return ans;
  }

  private long modPow(long x, long n, int mod) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % mod, (n - 1), mod) % mod;
    return modPow(x * x % mod, (n / 2), mod) % mod;
  }
}
