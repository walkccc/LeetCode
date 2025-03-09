class Solution {
  public int[] transformArray(int[] nums) {
    int[] ans = new int[nums.length];
    int[] count = new int[2];

    for (final int num : nums)
      ++count[num % 2];

    for (int i = 0; i < count[0]; ++i)
      ans[i] = 0;

    for (int i = count[0]; i < nums.length; ++i)
      ans[i] = 1;

    return ans;
  }
}
