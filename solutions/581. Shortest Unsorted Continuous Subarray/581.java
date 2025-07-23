class Solution {
  public int findUnsortedSubarray(int[] nums) {
    final int n = nums.length;
    int mn = Integer.MAX_VALUE;
    int mx = Integer.MIN_VALUE;
    boolean meetDecrease = false;
    boolean meetIncrease = false;

    for (int i = 1; i < n; ++i) {
      if (nums[i] < nums[i - 1])
        meetDecrease = true;
      if (meetDecrease)
        mn = Math.min(mn, nums[i]);
    }

    for (int i = n - 2; i >= 0; --i) {
      if (nums[i] > nums[i + 1])
        meetIncrease = true;
      if (meetIncrease)
        mx = Math.max(mx, nums[i]);
    }

    int l = 0;
    for (l = 0; l < n; ++l)
      if (nums[l] > mn)
        break;

    int r = 0;
    for (r = n - 1; r >= 0; --r)
      if (nums[r] < mx)
        break;

    return l > r ? 0 : r - l + 1;
  }
}
