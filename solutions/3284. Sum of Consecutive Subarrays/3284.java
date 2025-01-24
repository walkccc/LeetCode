class Solution {
  public int getSum(int[] nums) {
    final long sum = Arrays.stream(nums).asLongStream().sum() % kMod;
    return (int) ((getSum(nums, 1) + getSum(nums, -1) - sum) % kMod);
  }

  private static final int kMod = 1_000_000_007;

  // Returns the sum of all subarrays with a difference of `diff`.
  private long getSum(int[] nums, int diff) {
    long res = nums[0];
    long summ = nums[0];
    long count = 1;
    for (int i = 1; i < nums.length; ++i) {
      if (nums[i] == nums[i - 1] + diff) {
        count += 1;
        summ += count * nums[i];
      } else {
        count = 1;
        summ = nums[i];
      }
      res += summ;
      res %= kMod;
    }
    return res;
  }
}
