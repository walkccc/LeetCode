class Solution {
  public int partitionDisjoint(int[] nums) {
    final int n = nums.length;
    int[] min = new int[n];
    min[n - 1] = nums[n - 1];
    int max = Integer.MIN_VALUE;

    for (int i = n - 2; i >= 0; --i)
      min[i] = Math.min(min[i + 1], nums[i]);

    for (int i = 0; i < n; ++i) {
      max = Math.max(max, nums[i]);
      if (max <= min[i + 1])
        return i + 1;
    }

    throw new IllegalArgumentException();
  }
}
