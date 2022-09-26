class Solution {
  public int maximumGood(int[][] statements) {
    final int maxMask = 1 << statements.length;
    int ans = 0;

    for (int mask = 0; mask < maxMask; ++mask)
      if (isValid(statements, mask))
        ans = Math.max(ans, Integer.bitCount(mask));

    return ans;
  }

  private boolean isValid(int[][] statements, int mask) {
    for (int i = 0; i < statements.length; ++i) {
      if ((mask >> i & 1) == 0) // i-th person is bad, no need to check
        continue;
      for (int j = 0; j < statements.length; ++j) {
        if (statements[i][j] == 2)
          continue;
        if (statements[i][j] != (mask >> j & 1))
          return false;
      }
    }
    return true;
  }
}
