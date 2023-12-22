class Solution {
  public int jump(int[] nums) {
    int ans = 0;
    int end = 0;
    int farthest = 0;

    for (int i = 0; i < nums.length; ++i) {
      if (end < i) {
        end = farthest;
        ++ans;
      }
      farthest = Math.max(farthest, i + nums[i]);
    }

    return ans;
  }
}
