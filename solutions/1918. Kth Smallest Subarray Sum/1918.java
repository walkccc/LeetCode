class Solution {
  public int kthSmallestSubarraySum(int[] nums, int k) {
    int l = 0;
    int r = Arrays.stream(nums).sum();

    while (l < r) {
      final int m = (l + r) / 2;
      if (numSubarrayLessThan(nums, m) >= k)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  private int numSubarrayLessThan(int[] nums, int m) {
    int res = 0;
    int sum = 0;
    for (int l = 0, r = 0; r < nums.length; ++r) {
      sum += nums[r];
      while (sum > m)
        sum -= nums[l++];
      res += r - l + 1;
    }
    return res;
  }
}
