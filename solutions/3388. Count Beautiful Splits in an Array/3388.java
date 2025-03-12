class Solution {
  public int beautifulSplits(int[] nums) {
    final int n = nums.length;
    int ans = 0;
    // z[start][i] := the z array of nums[i..n) with respect to nums[start..n)
    int[][] z = new int[n][];

    for (int start = 0; start < n; ++start)
      z[start] = zFunction(nums, start);

    // nums1 | nums2 | nums3 = nums[0..i] | nums[i + 1..j] | nums[j + 1..n - 1]
    for (int i = 0; i < n - 2; ++i)
      for (int j = i + 1; j < n - 1; ++j)
        if ((j - i >= i + 1 && z[0][i + 1] >= i + 1) || // nums1 is a prefix of nums2.
            z[i + 1][j + 1] >= j - i)                   // nums2 is a suffix of nums3.
          ++ans;

    return ans;
  }

  // Returns the z array, where z[i] is the length of the longest prefix of
  // nums[i..n) which is also a prefix of nums[start..n).
  private int[] zFunction(int[] nums, int start) {
    final int n = nums.length;
    int[] z = new int[n];
    int l = 0;
    int r = 0;
    for (int i = 1 + start; i < n; ++i) {
      if (i < r)
        z[i] = Math.min(r - i, z[i - l + start]);
      while (i + z[i] < n && nums[z[i] + start] == nums[i + z[i]])
        ++z[i];
      if (i + z[i] > r) {
        l = i;
        r = i + z[i];
      }
    }
    return z;
  }
}
