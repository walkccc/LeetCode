class Solution {
  public int findClosestNumber(int[] nums) {
    int ans = 0;
    int mn = Integer.MAX_VALUE;

    for (final int num : nums)
      if (Math.abs(num) < mn) {
        mn = Math.abs(num);
        ans = num;
      } else if (Math.abs(num) == mn && num > ans) {
        ans = num;
      }

    return ans;
  }
}
