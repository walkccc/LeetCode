class Solution {
  public int singleNumber(int[] nums) {
    int ans = 0;

    for (final int num : nums)
      ans ^= num;

    return ans;
  }
}