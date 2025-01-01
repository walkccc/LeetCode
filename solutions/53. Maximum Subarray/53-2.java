class Solution {
  public int maxSubArray(int[] nums) {
    int ans = Integer.MIN_VALUE;
    int sum = 0;

    for (final int num : nums) {
      sum = Math.max(num, sum + num);
      ans = Math.max(ans, sum);
    }

    return ans;
  }
}
