class Solution {
  public int findPeakElement(int[] nums) {
    int l = 0;
    int r = nums.length - 1;

    // find the first index l s.t. nums[l] >= nums[l + 1]
    while (l < r) {
      final int m = l + (r - l) / 2;
      if (nums[m] < nums[m + 1])
        l = m + 1;
      else
        r = m;
    }

    return l;
  }
}