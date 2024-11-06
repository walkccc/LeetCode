class Solution {
  public long maximumSumScore(int[] nums) {
    long ans = Long.MIN_VALUE;
    long prefix = 0;
    long sum = Arrays.stream(nums).asLongStream().sum();

    for (final int num : nums) {
      prefix += num;
      ans = Math.max(ans, Math.max(prefix, sum - prefix + num));
    }

    return ans;
  }
}
