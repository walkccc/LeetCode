class Solution {
  public int[] productQueries(int n, int[][] queries) {
    final int kMod = 1_000_000_007;
    final int kMaxBit = 30;
    int[] ans = new int[queries.length];
    List<Integer> powers = new ArrayList<>();

    for (int i = 0; i < kMaxBit; ++i)
      if ((n >> i & 1) == 1)
        powers.add(1 << i);

    for (int i = 0; i < queries.length; ++i) {
      final int left = queries[i][0];
      final int right = queries[i][1];
      long prod = 1;
      for (int j = left; j <= right; ++j) {
        prod *= powers.get(j);
        prod %= kMod;
      }
      ans[i] = (int) prod;
    }

    return ans;
  }
}
