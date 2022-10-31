class Solution {
  public int maxValueAfterReverse(int[] nums) {
    int total = 0;
    int min = Integer.MAX_VALUE;
    int max = Integer.MIN_VALUE;

    for (int i = 0; i + 1 < nums.length; ++i) {
      int a = nums[i];
      int b = nums[i + 1];
      total += Math.abs(a - b);
      min = Math.min(min, Math.max(a, b));
      max = Math.max(max, Math.min(a, b));
    }
    int diff = Math.max(0, (max - min) * 2);

    for (int i = 0; i + 1 < nums.length; ++i) {
      int a = nums[i];
      int b = nums[i + 1];
      int headDiff = -Math.abs(a - b) + Math.abs(nums[0] - b);
      int tailDiff = -Math.abs(a - b) + Math.abs(nums[nums.length - 1] - a);
      diff = Math.max(diff, Math.max(headDiff, tailDiff));
    }

    return total + diff;
  }
}
