class Solution {
  public int maxValueAfterReverse(int[] nums) {
    int total = 0;
    int mn = Integer.MAX_VALUE;
    int mx = Integer.MIN_VALUE;

    for (int i = 0; i + 1 < nums.length; ++i) {
      final int a = nums[i];
      final int b = nums[i + 1];
      total += Math.abs(a - b);
      mn = Math.min(mn, Math.max(a, b));
      mx = Math.max(mx, Math.min(a, b));
    }
    int diff = Math.max(0, (mx - mn) * 2);

    for (int i = 0; i + 1 < nums.length; ++i) {
      final int a = nums[i];
      final int b = nums[i + 1];
      final int headDiff = -Math.abs(a - b) + Math.abs(nums[0] - b);
      final int tailDiff = -Math.abs(a - b) + Math.abs(nums[nums.length - 1] - a);
      diff = Math.max(diff, Math.max(headDiff, tailDiff));
    }

    return total + diff;
  }
}
