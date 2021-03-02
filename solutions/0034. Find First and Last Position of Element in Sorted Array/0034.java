class Solution {
  public int[] searchRange(int[] nums, int target) {
    final int start = firstGreaterEqual(nums, target);
    if (start == nums.length || nums[start] != target)
      return new int[] {-1, -1};
    final int end = firstGreaterEqual(nums, target + 1) - 1;
    return new int[] {start, end};
  }

  // find the first index l s.t nums[l] >= target
  // return nums.length if can'f find
  private int firstGreaterEqual(int[] nums, int target) {
    int l = 0;
    int r = nums.length;

    while (l < r) {
      final int m = l + (r - l) / 2;
      if (nums[m] >= target)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
}
