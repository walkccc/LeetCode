class Solution {
  public long countSubarrays(int[] nums) {
    long ans = 0;

    for (int i = 0, j = -1; i < nums.length; ++i) {
      if (i > 0 && nums[i] <= nums[i - 1])
        j = i - 1;
      ans += i - j;
    }

    return ans;
  }
}
