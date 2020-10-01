class Solution {
  public int jump(int[] nums) {
    int ans = 0;
    int end = 0;
    int farthest = 0;

    for (int i = 0; i + 1 < nums.length; ++i) {
      farthest = Math.max(farthest, i + nums[i]);
      if (i == end) {
        ++ans;
        end = farthest;
      }
    }

    return ans;
  }
}