class Solution {
  public int maxAbsoluteSum(int[] nums) {
    int sum = 0;
    int maxPrefix = 0;
    int minPrefix = 0;

    for (final int num : nums) {
      sum += num;
      maxPrefix = Math.max(maxPrefix, sum);
      minPrefix = Math.min(minPrefix, sum);
    }

    return maxPrefix - minPrefix;
  }
}
