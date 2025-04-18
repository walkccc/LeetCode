class Solution {
  public int makeArrayPositive(int[] nums) {
    final long kMax = 1_000_000_000_000_000_000L;
    int ans = 0;
    long minSum = nums[0] + nums[1];
    long[] bigNums = Arrays.stream(nums).mapToLong(i -> i).toArray();

    for (int i = 2; i < bigNums.length; ++i) {
      final long a = bigNums[i - 2];
      final long b = bigNums[i - 1];
      final long c = bigNums[i];
      minSum = Math.min(minSum + c, a + b + c);
      if (minSum <= 0) {
        bigNums[i] = kMax;
        minSum = kMax;
        ++ans;
      }
    }

    return ans;
  }
}
