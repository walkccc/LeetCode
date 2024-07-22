class Solution {
  public int maxNumOfMarkedIndices(int[] nums) {
    Arrays.sort(nums);

    int l = 0;
    int r = nums.length / 2 + 1;

    while (l < r) {
      final int m = (l + r) / 2;
      if (isPossible(nums, m))
        l = m + 1;
      else
        r = m;
    }

    return (l - 1) * 2;
  }

  private boolean isPossible(int[] nums, int m) {
    for (int i = 0; i < m; ++i)
      if (2 * nums[i] > nums[nums.length - m + i])
        return false;
    return true;
  }
}
