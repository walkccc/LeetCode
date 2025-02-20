class Solution {
  public int minimumIncrements(int[] nums, int[] target) {
    final int maxMask = 1 << target.length;
    Map<Integer, Long> maskToLcm = new HashMap<>();

    for (int mask = 1; mask < maxMask; ++mask) {
      List<Integer> subset = getSubset(mask, target);
      maskToLcm.put(mask, getLcm(subset));
    }

    // dp[mask] := the minimum number of increments to make each number in the
    // subset of target have at least one number that is a multiple in `num`,
    // where `mask` is the bitmask of the subset of target
    long[] dp = new long[maxMask];
    Arrays.fill(dp, Long.MAX_VALUE);
    dp[0] = 0;

    for (final int num : nums) {
      // maskToCost := (mask, cost), where `mask` is the bitmask of the subset
      // of target and `cost` is the minimum number of increments to make each
      // number in the subset of target have at least one number that is a
      // multiple in `num`
      List<Pair<Integer, Long>> maskToCost = new ArrayList<>();
      for (Map.Entry<Integer, Long> entry : maskToLcm.entrySet()) {
        final int mask = entry.getKey();
        final long lcm = entry.getValue();
        final long remainder = num % lcm;
        maskToCost.add(new Pair<>(mask, remainder == 0 ? 0 : lcm - remainder));
      }
      long[] newDp = dp.clone();
      for (int prevMask = 0; prevMask < maxMask; ++prevMask) {
        if (dp[prevMask] == Long.MAX_VALUE)
          continue;
        for (Pair<Integer, Long> pair : maskToCost) {
          final int mask = pair.getKey();
          final long cost = pair.getValue();
          final int nextMask = prevMask | mask;
          newDp[nextMask] = Math.min(newDp[nextMask], dp[prevMask] + cost);
        }
      }
      dp = newDp;
    }

    return dp[maxMask - 1] == Long.MAX_VALUE ? -1 : (int) dp[maxMask - 1];
  }

  private List<Integer> getSubset(int mask, int[] target) {
    List<Integer> subset = new ArrayList<>();
    for (int i = 0; i < target.length; ++i)
      if ((mask >> i & 1) == 1)
        subset.add(target[i]);
    return subset;
  }

  private long getLcm(List<Integer> nums) {
    long res = 1;
    for (final int num : nums)
      res = lcm(res, num);
    return res;
  }

  private long lcm(long a, long b) {
    return a * b / gcd(a, b);
  }

  private long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
