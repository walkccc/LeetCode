class Solution {
  public int longestNiceSubarray(int[] nums) {
    int ans = 0;
    int usedBits = 0;

    for (int l = 0, r = 0; r < nums.length; ++r) {
      while ((usedBits & nums[r]) > 0)
        usedBits ^= nums[l++];
      usedBits |= nums[r];
      ans = Math.max(ans, r - l + 1);
    }

    return ans;
  }
}
