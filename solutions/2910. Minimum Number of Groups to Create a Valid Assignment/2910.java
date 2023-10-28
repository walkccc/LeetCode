class Solution {
  public int minGroupsForValidAssignment(int[] nums) {
    Map<Integer, Integer> count = new HashMap<>();
    int minFreq = nums.length;

    for (final int num : nums)
      count.merge(num, 1, Integer::sum);

    for (final int freq : count.values())
      minFreq = Math.min(minFreq, freq);

    for (int groupSize = minFreq; groupSize >= 1; --groupSize) {
      final int numGroups = getNumGroups(count, groupSize);
      if (numGroups > 0)
        return numGroups;
    }

    throw new IllegalArgumentException();
  }

  // Returns the number of groups if each group's size is `groupSize` or
  // `groupSize + 1`.
  private int getNumGroups(Map<Integer, Integer> count, int groupSize) {
    int numGroups = 0;
    for (final int freq : count.values()) {
      final int a = freq / (groupSize + 1);
      final int b = freq % (groupSize + 1);
      if (b == 0) {
        numGroups += a;
      } else if (groupSize - b <= a) {
        // Assign 1 number from `groupSize - b` out of `a` groups to this group,
        // so we'll have `a - (groupSize - b)` groups of size `groupSize + 1`
        // and `groupSize - b + 1` groups of size `groupSize`. In total, we have
        // `a + 1` groups.
        numGroups += a + 1;
      } else {
        return 0;
      }
    }
    return numGroups;
  }
}
