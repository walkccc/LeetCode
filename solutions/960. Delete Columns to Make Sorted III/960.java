class Solution {
  public int minDeletionSize(String[] strs) {
    final int k = strs[0].length();
    // dp[i] the length of LIS ending in strs[*][i]
    int[] dp = new int[k];
    Arrays.fill(dp, 1);

    for (int i = 1; i < k; ++i)
      for (int j = 0; j < i; ++j)
        if (isSorted(strs, j, i))
          dp[i] = Math.max(dp[i], dp[j] + 1);

    return k - Arrays.stream(dp).max().getAsInt();
  }

  private boolean isSorted(String[] strs, int j, int i) {
    for (final String s : strs)
      if (s.charAt(j) > s.charAt(i))
        return false;
    return true;
  }
}
