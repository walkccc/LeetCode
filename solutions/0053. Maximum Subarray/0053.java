class Solution {
  public int maxSubArray(int[] nums) {
    int ans = Integer.MIN_VALUE;
    int sum = 0;

    for (final int num : nums) {
      sum += num;
      ans = Math.max(ans, sum);
      sum = Math.max(sum, 0);
    }

    return ans;
  }
}
