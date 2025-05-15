class Solution {
  public int[] productQueries(int n, int[][] queries) {
    final int MOD = 1_000_000_007;
    final int MAX_BIT = 30;
    int[] ans = new int[queries.length];
    List<Integer> pows = new ArrayList<>();

    for (int i = 0; i < MAX_BIT; ++i)
      if ((n >> i & 1) == 1)
        pows.add(1 << i);

    for (int i = 0; i < queries.length; ++i) {
      final int left = queries[i][0];
      final int right = queries[i][1];
      long prod = 1;
      for (int j = left; j <= right; ++j) {
        prod *= pows.get(j);
        prod %= MOD;
      }
      ans[i] = (int) prod;
    }

    return ans;
  }
}
