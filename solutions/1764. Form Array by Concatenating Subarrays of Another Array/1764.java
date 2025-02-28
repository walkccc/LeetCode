class Solution {
  public boolean canChoose(int[][] groups, int[] nums) {
    int i = 0; // groups' index
    int j = 0; // nums' index

    while (i < groups.length && j < nums.length)
      if (isMatch(groups[i], nums, j)) {
        j += groups[i].length;
        ++i;
      } else {
        ++j;
      }

    return i == groups.length;
  }

  // Returns true if group == nums[j..j + |group|].
  private boolean isMatch(int[] group, int[] nums, int j) {
    if (j + group.length > nums.length)
      return false;
    for (int i = 0; i < group.length; ++i)
      if (group[i] != nums[j + i])
        return false;
    return true;
  }
}
