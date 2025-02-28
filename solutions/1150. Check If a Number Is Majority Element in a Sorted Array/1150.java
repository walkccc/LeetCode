class Solution {
  public boolean isMajorityElement(int[] nums, int target) {
    final int n = nums.length;
    final int i = firstGreaterEqual(nums, target);
    return i + n / 2 < n && nums[i + n / 2] == target;
  }

  private int firstGreaterEqual(int[] arr, int target) {
    int l = 0;
    int r = arr.length;
    while (l < r) {
      final int m = (l + r) / 2;
      if (arr[m] >= target)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
}
