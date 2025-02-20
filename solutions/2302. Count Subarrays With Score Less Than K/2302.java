class Solution {
  public long countSubarrays(int[] nums, long k) {
    long ans = 0;
    long sum = 0;

    for (int l = 0, r = 0; r < nums.length; ++r) {
      sum += nums[r];
      while (sum * (r - l + 1) >= k)
        sum -= nums[l++];
      ans += r - l + 1;
    }

    return ans;
  }
}
