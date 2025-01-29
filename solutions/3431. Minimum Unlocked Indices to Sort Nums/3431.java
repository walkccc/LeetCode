class Solution {
  public int minUnlockedIndices(int[] nums, int[] locked) {
    final int first2 = findFirstIndex(nums, 2);
    final int first3 = findFirstIndex(nums, 3);
    final int last1 = findLastIndex(nums, 1);
    final int last2 = findLastIndex(nums, 2);
    if (first3 != -1 && last1 != -1 && first3 < last1)
      return -1;

    int ans = 0;

    // Unlocked indices between 2 and 1.
    if (first2 != -1 && last1 != -1)
      for (int i = first2; i < last1; ++i)
        if (locked[i] == 1)
          ++ans;

    // Unlocked indices between 3 and 2.
    if (first3 != -1 && last2 != -1)
      for (int i = first3; i < last2; i++)
        if (locked[i] == 1)
          ++ans;

    return ans;
  }

  private int findFirstIndex(int[] nums, int target) {
    for (int i = 0; i < nums.length; ++i)
      if (nums[i] == target)
        return i;
    return -1;
  }

  private int findLastIndex(int[] nums, int target) {
    for (int i = nums.length - 1; i >= 0; i--)
      if (nums[i] == target)
        return i;
    return -1;
  }
}
