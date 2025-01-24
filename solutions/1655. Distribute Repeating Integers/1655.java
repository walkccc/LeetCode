class Solution {
  public boolean canDistribute(int[] nums, int[] quantity) {
    List<Integer> freqs = getFreqs(nums);
    // validDistribution[i][j] := true if it's possible to distribute the i-th
    // freq into a subset of quantity represented by the bitmask j
    boolean[][] validDistribution = getValidDistribution(freqs, quantity);
    final int n = freqs.size();
    final int m = quantity.length;
    final int maxMask = 1 << m;
    // dp[i][j] := true if it's possible to distribute freqs[i..n), where j is
    // the bitmask of the selected quantity
    boolean[][] dp = new boolean[n + 1][maxMask];
    dp[n][maxMask - 1] = true;

    for (int i = n - 1; i >= 0; --i)
      for (int mask = 0; mask < maxMask; ++mask) {
        dp[i][mask] = dp[i + 1][mask];
        final int availableMask = ~mask & (maxMask - 1);
        for (int submask = availableMask; submask > 0; submask = (submask - 1) & availableMask)
          if (validDistribution[i][submask])
            dp[i][mask] = dp[i][mask] || dp[i + 1][mask | submask];
      }

    return dp[0][0];
  }

  private List<Integer> getFreqs(int[] nums) {
    List<Integer> freqs = new ArrayList<>();
    Map<Integer, Integer> count = new HashMap<>();
    for (final int num : nums)
      count.merge(num, 1, Integer::sum);
    return new ArrayList<>(count.values());
  }

  boolean[][] getValidDistribution(List<Integer> freqs, int[] quantity) {
    final int maxMask = 1 << quantity.length;
    boolean[][] validDistribution = new boolean[freqs.size()][maxMask];
    for (int i = 0; i < freqs.size(); ++i)
      for (int mask = 0; mask < maxMask; ++mask)
        if (freqs.get(i) >= getQuantitySum(quantity, mask))
          validDistribution[i][mask] = true;
    return validDistribution;
  }

  // Returns the sum of the selected quantity represented by `mask`.
  int getQuantitySum(int[] quantity, int mask) {
    int sum = 0;
    for (int i = 0; i < quantity.length; ++i)
      if ((mask >> i & 1) == 1)
        sum += quantity[i];
    return sum;
  }
}
