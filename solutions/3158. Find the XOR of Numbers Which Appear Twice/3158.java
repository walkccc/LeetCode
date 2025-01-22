class Solution {
  public int duplicateNumbersXOR(int[] nums) {
    final int kMax = 50;
    int ans = 0;
    int[] count = new int[kMax + 1];

    for (final int num : nums)
      ++count[num];

    for (int num = 1; num <= kMax; ++num)
      if (count[num] == 2)
        ans ^= num;

    return ans;
  }
}
