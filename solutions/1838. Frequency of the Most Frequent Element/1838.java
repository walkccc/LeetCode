class Solution {
  public int maxFrequency(int[] nums, int k) {
    int ans = 0;
    long sum = 0;

    Arrays.sort(nums);

    for (int l = 0, r = 0; r < nums.length; ++r) {
      sum += nums[r];
      while (sum + k < (long) nums[r] * (r - l + 1))
        sum -= nums[l++];
      ans = Math.max(ans, r - l + 1);
    }

    return ans;
  }
}
