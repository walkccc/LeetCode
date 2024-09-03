class Solution {
  // Same as 3254. Find the Power of K-Size Subarrays I
  public int[] resultsArray(int[] nums, int k) {
    final int n = nums.length;
    int[] ans = new int[n - k + 1];
    int start = 0;

    for (int i = 0; i < n; ++i) {
      if (i > 0 && nums[i] != nums[i - 1] + 1)
        start = i;
      if (i >= k - 1)
        ans[i - k + 1] = i - start + 1 >= k ? nums[i] : -1;
    }

    return ans;
  }
}
