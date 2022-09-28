class Solution {
  public int[] singleNumber(int[] nums) {
    final int xors = Arrays.stream(nums).reduce((a, b) -> a ^ b).getAsInt();
    final int lowbit = xors & -xors;
    int[] ans = new int[2];

    // seperate nums into two groups by the lowbit
    for (final int num : nums)
      if ((num & lowbit) > 0)
        ans[0] ^= num;
      else
        ans[1] ^= num;

    return ans;
  }
}
