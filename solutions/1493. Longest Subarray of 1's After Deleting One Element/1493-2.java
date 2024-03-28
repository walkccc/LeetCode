class Solution {
  public int longestSubarray(int[] nums) {
    int l = 0;
    int count0 = 0;

    for (final int num : nums) {
      if (num == 0)
        ++count0;
      if (count0 > 1 && nums[l++] == 0)
        --count0;
    }

    return nums.length - l - 1;
  }
}
