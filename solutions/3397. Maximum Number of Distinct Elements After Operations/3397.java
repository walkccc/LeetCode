class Solution {
  public int maxDistinctElements(int[] nums, int k) {
    int ans = 0;
    int occupied = Integer.MIN_VALUE;

    Arrays.sort(nums);

    for (final int num : nums)
      if (occupied < num + k) {
        occupied = Math.max(occupied + 1, num - k);
        ++ans;
      }

    return ans;
  }
}
