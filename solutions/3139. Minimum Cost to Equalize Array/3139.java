class Solution {
  public int minCostToEqualizeArray(int[] nums, int cost1, int cost2) {
    final int kMod = 1_000_000_007;
    final int n = nums.length;
    final int minNum = Arrays.stream(nums).min().getAsInt();
    final int maxNum = Arrays.stream(nums).max().getAsInt();
    final long sum = Arrays.stream(nums).asLongStream().sum();
    long ans = Long.MAX_VALUE;

    if (cost1 * 2 <= cost2 || n < 3) {
      final long totalGap = 1L * maxNum * n - sum;
      return (int) ((cost1 * totalGap) % kMod);
    }

    for (int target = maxNum; target < 2 * maxNum; ++target) {
      final int maxGap = target - minNum;
      final long totalGap = 1L * target * n - sum;
      final long pairs = Math.min(totalGap / 2, totalGap - maxGap);
      ans = Math.min(ans, cost1 * (totalGap - 2 * pairs) + cost2 * pairs);
    }

    return (int) (ans % kMod);
  }
}
