class Solution {
  public int[] singleNumber(int[] nums) {
    int xors = 0;
    for (final int num : nums)
      xors ^= num;

    final int lowbit = xors & -xors;

    int[] ans = new int[2];

    for (final int num : nums)
      if ((num & lowbit) > 0)
        ans[0] ^= num;
      else
        ans[1] ^= num;

    return ans;
  }
}
