class Solution {
  public int[] distinctDifferenceArray(int[] nums) {
    final int kMax = 50;
    int[] ans = new int[nums.length];
    int[] prefixCount = new int[kMax + 1];
    int[] suffixCount = new int[kMax + 1];
    int distinctPrefix = 0;
    int distinctSuffix = 0;

    for (final int num : nums)
      if (++suffixCount[num] == 1)
        ++distinctSuffix;

    for (int i = 0; i < nums.length; ++i) {
      if (++prefixCount[nums[i]] == 1)
        ++distinctPrefix;
      if (--suffixCount[nums[i]] == 0)
        --distinctSuffix;
      ans[i] = distinctPrefix - distinctSuffix;
    }

    return ans;
  }
}
