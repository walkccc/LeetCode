class Solution {
  public int partitionDisjoint(int[] nums) {
    final int n = nums.length;
    int[] mn = new int[n];
    mn[n - 1] = nums[n - 1];
    int mx = Integer.MIN_VALUE;

    for (int i = n - 2; i >= 0; --i)
      mn[i] = Math.min(mn[i + 1], nums[i]);

    for (int i = 0; i < n; ++i) {
      mx = Math.max(mx, nums[i]);
      if (mx <= mn[i + 1])
        return i + 1;
    }

    throw new IllegalArgumentException();
  }
}
