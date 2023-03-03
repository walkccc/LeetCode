class Solution {
  public int longestOnes(int[] nums, int k) {
    int ans = 0;

    for (int l = 0, r = 0; r < nums.length; ++r) {
      if (nums[r] == 0)
        --k;
      while (k < 0)
        if (nums[l++] == 0)
          ++k;
      ans = Math.max(ans, r - l + 1);
    }

    return ans;
  }
}
