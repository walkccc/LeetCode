class Solution {
  public int maxSumAfterOperation(int[] nums) {
    int ans = Integer.MIN_VALUE;
    int regular = 0;
    int squared = 0;

    for (final int num : nums) {
      squared = Math.max(num * num, Math.max(regular + num * num, squared + num));
      regular = Math.max(num, regular + num);
      ans = Math.max(ans, squared);
    }

    return ans;
  }
}
