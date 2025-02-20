class Solution {
  public int longestSubarray(int[] nums) {
    int l = 0;
    int zeros = 0;

    for (final int num : nums) {
      if (num == 0)
        ++zeros;
      if (zeros > 1 && nums[l++] == 0)
        --zeros;
    }

    return nums.length - l - 1;
  }
}
