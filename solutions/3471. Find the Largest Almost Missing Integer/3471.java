class Solution {
  public int largestInteger(int[] nums, int k) {
    if (k == nums.length)
      return Arrays.stream(nums).max().getAsInt();
    int[] count = getCount(nums);
    if (k == 1)
      return maxUnique(nums, count);
    return Math.max(count[nums[0]] == 1 ? nums[0] : -1,
                    count[nums[nums.length - 1]] == 1 ? nums[nums.length - 1] : -1);
  }

  // Returns the maximum unique integer in nums if any. Otherwise, returns -1.
  private int maxUnique(int[] nums, int[] count) {
    return Arrays.stream(nums).filter(num -> count[num] == 1).max().orElse(-1);
  }

  private int[] getCount(int[] nums) {
    final int MAX = 50;
    int[] count = new int[MAX + 1];
    for (final int num : nums)
      ++count[num];
    return count;
  }
}
