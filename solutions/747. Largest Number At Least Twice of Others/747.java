class Solution {
  public int dominantIndex(int[] nums) {
    int ans = 0;
    int mx = 0;
    int secondMax = 0;

    for (int i = 0; i < nums.length; ++i)
      if (nums[i] > mx) {
        secondMax = mx;
        mx = nums[i];
        ans = i;
      } else if (nums[i] > secondMax) {
        secondMax = nums[i];
      }

    return mx >= 2 * secondMax ? ans : -1;
  }
}
