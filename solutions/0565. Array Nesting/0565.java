class Solution {
  public int arrayNesting(int[] nums) {
    int ans = 0;

    for (final int num : nums) {
      if (num == -1)
        continue;
      int index = num;
      int count = 0;
      while (nums[index] != -1) { // Not yet seen
        final int cache = index;
        index = nums[index]; // Get next index
        nums[cache] = -1;    // Already seen
        ++count;
      }
      ans = Math.max(ans, count);
    }

    return ans;
  }
}
