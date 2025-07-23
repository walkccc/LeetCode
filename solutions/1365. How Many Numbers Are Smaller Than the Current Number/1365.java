class Solution {
  public int[] smallerNumbersThanCurrent(int[] nums) {
    final int MAX = 100;
    int[] ans = new int[nums.length];
    int[] count = new int[MAX + 1];

    for (final int num : nums)
      ++count[num];

    for (int i = 1; i <= MAX; ++i)
      count[i] += count[i - 1];

    for (int i = 0; i < nums.length; ++i)
      ans[i] = nums[i] == 0 ? 0 : count[nums[i] - 1];

    return ans;
  }
}
