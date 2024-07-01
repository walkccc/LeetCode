class Solution {
  public int longestSubarray(int[] nums) {
    int ans = 0;
    int count0 = 0;

    for (int l = 0, r = 0; r < nums.length; ++r) {
      if (nums[r] == 0)
        ++count0;
      while (count0 == 2)
        if (nums[l++] == 0)
          --count0;
      ans = Math.max(ans, r - l);
    }

    return ans;
  }
}
