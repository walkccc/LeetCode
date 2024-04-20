class Solution {
  public int dominantIndex(int[] nums) {
    int ans = 0;
    int max = 0;
    int secondMax = 0;

    for (int i = 0; i < nums.length; ++i)
      if (nums[i] > max) {
        secondMax = max;
        max = nums[i];
        ans = i;
      } else if (nums[i] > secondMax) {
        secondMax = nums[i];
      }

    return max >= 2 * secondMax ? ans : -1;
  }
}
