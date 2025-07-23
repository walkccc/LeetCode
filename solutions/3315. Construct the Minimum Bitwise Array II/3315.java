class Solution {
  // Same as 3314. Construct the Minimum Bitwise Array I
  public int[] minBitwiseArray(List<Integer> nums) {
    int[] ans = new int[nums.size()];

    for (int i = 0; i < nums.size(); ++i)
      ans[i] = nums.get(i) == 2 ? -1 : nums.get(i) - getLeadingOneOfLastGroupOfOnes(nums.get(i));

    return ans;
  }

  // Returns the leading one of the last group of 1s in the binary
  // representation of num. For example, if num = 0b10111, the leading one of
  // the last group of 1s is 0b100.
  private int getLeadingOneOfLastGroupOfOnes(int num) {
    int leadingOne = 1;
    while ((num & leadingOne) > 0)
      leadingOne <<= 1;
    return leadingOne >> 1;
  }
}
