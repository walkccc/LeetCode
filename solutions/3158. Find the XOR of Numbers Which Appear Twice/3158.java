class Solution {
  public int duplicateNumbersXOR(int[] nums) {
    final int MAX = 50;
    int ans = 0;
    int[] count = new int[MAX + 1];

    for (final int num : nums)
      ++count[num];

    for (int num = 1; num <= MAX; ++num)
      if (count[num] == 2)
        ans ^= num;

    return ans;
  }
}
