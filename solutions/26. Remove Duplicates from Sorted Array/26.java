class Solution {
  public int removeDuplicates(int[] nums) {
    int i = 0;

    for (final int num : nums)
      if (i < 1 || num > nums[i - 1])
        nums[i++] = num;

    return i;
  }
}
