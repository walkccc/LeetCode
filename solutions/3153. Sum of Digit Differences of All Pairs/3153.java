class Solution {
  public long sumDigitDifferences(int[] nums) {
    final int n = nums.length;
    final int digitSize = String.valueOf(nums[0]).length();
    long ans = 0;

    for (int i = 0, denominator = 1; i < digitSize; ++i, denominator *= 10) {
      int[] count = new int[10];
      for (final int num : nums)
        ++count[num / denominator % 10];
      for (final int freq : count)
        ans += freq * (n - freq);
    }

    return ans / 2;
  }
}
