class Solution {
  public int minimumSubarrayLength(int[] nums, int k) {
    final int kMax = 50;
    final int n = nums.length;
    int ans = n + 1;
    int ors = 0;
    int[] count = new int[kMax + 1];

    for (int l = 0, r = 0; r < n; ++r) {
      ors = orNum(ors, nums[r], count);
      while (ors >= k && l <= r) {
        ans = Math.min(ans, r - l + 1);
        ors = undoOrNum(ors, nums[l], count);
        ++l;
      }
    }

    return (ans == n + 1) ? -1 : ans;
  }

  private static final int kMaxBit = 30;

  private int orNum(int ors, int num, int[] count) {
    for (int i = 0; i < kMaxBit; ++i)
      if ((num >> i & 1) == 1 && ++count[i] == 1)
        ors += 1 << i;
    return ors;
  }

  private int undoOrNum(int ors, int num, int[] count) {
    for (int i = 0; i < kMaxBit; ++i)
      if ((num >> i & 1) == 1 && --count[i] == 0)
        ors -= 1 << i;
    return ors;
  }
}
