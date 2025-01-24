class Solution {
  public int countKDifference(int[] nums, int k) {
    final int kMax = 100;
    int ans = 0;
    int[] count = new int[kMax + 1];

    for (final int num : nums)
      ++count[num];

    for (int i = k + 1; i <= kMax; ++i)
      ans += count[i] * count[i - k];

    return ans;
  }
}
