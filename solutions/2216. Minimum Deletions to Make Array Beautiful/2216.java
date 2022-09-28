class Solution {
  public int minDeletion(int[] nums) {
    int ans = 0;

    for (int i = 0; i + 1 < nums.length; ++i)
      // i - ans := index after deletion
      if (nums[i] == nums[i + 1] && (i - ans) % 2 == 0)
        ++ans;

    return ans + (((nums.length - ans) & 1) == 1 ? 1 : 0);
  }
}
