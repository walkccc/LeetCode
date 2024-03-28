class Solution {
  public int[] productExceptSelf(int[] nums) {
    final int n = nums.length;
    int[] ans = new int[n];
    ans[0] = 1;

    // Use ans as the prefix product array.
    for (int i = 1; i < n; ++i)
      ans[i] = ans[i - 1] * nums[i - 1];

    int suffix = 1; // suffix product
    for (int i = n - 1; i >= 0; --i) {
      ans[i] *= suffix;
      suffix *= nums[i];
    }

    return ans;
  }
}
