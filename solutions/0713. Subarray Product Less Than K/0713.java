class Solution {
  public int numSubarrayProductLessThanK(int[] nums, int k) {
    if (k <= 1)
      return 0;

    int ans = 0;
    int prod = 1;

    for (int l = 0, r = 0; r < nums.length; ++r) {
      prod *= nums[r];
      while (prod >= k)
        prod /= nums[l++];
      ans += r - l + 1;
    }

    return ans;
  }
}
