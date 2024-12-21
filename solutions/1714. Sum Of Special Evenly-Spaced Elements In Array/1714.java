class Solution {
  public int[] solve(int[] nums, int[][] queries) {
    final int kMod = 1_000_000_007;
    final int n = nums.length;
    final int sqrtN = (int) Math.sqrt(n);
    int[] ans = new int[queries.length];
    // prefix[x][y] = sum(nums[x + ay]), where a >= 0 and x + ay < n
    int[][] prefix = new int[n][sqrtN];

    // Set prefix[i][j] to nums[i] to indicate the sequence starts with nums[i].
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < sqrtN; ++j)
        prefix[i][j] = nums[i];

    for (int x = n - 1; x >= 0; --x)
      for (int y = 1; y < sqrtN; ++y)
        if (x + y < n) {
          prefix[x][y] += prefix[x + y][y];
          prefix[x][y] %= kMod;
        }

    for (int i = 0; i < queries.length; ++i) {
      final int x = queries[i][0];
      final int y = queries[i][1];
      if (y < sqrtN) {
        ans[i] = prefix[x][y];
      } else {
        int sum = 0;
        for (int j = x; j < n; j += y)
          sum = (sum + nums[j]) % kMod;
        ans[i] = sum;
      }
    }

    return ans;
  }
}
