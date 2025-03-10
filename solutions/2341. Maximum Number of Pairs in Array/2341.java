class Solution {
  public int[] numberOfPairs(int[] nums) {
    final int MAX = 100;
    int[] ans = new int[2];
    int[] count = new int[MAX + 1];

    for (final int num : nums)
      ++count[num];

    for (int i = 0; i <= MAX; ++i) {
      ans[0] += count[i] / 2;
      if (count[i] % 2 == 1)
        ++ans[1];
    }

    return ans;
  }
}
