class Solution {
  public long maximumAlternatingSubarraySum(int[] nums) {
    long ans = Integer.MIN_VALUE;
    long even = 0; // subarray sum starting from an even index
    long odd = 0;  // subarray sum starting from an odd index

    for (int i = 0; i < nums.length; ++i) {
      if (i % 2 == 0) // must pick
        even += nums[i];
      else // fresh start or minus
        even = Math.max(0, even - nums[i]);
      ans = Math.max(ans, even);
    }

    for (int i = 1; i < nums.length; ++i) {
      if (i % 2 == 1) // must pick
        odd += nums[i];
      else // fresh start or minus
        odd = Math.max(0, odd - nums[i]);
      ans = Math.max(ans, odd);
    }

    return ans;
  }
}
