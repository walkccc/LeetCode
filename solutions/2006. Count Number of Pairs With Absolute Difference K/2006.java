class Solution {
  public int countKDifference(int[] nums, int k) {
    final int MAX = 100;
    int ans = 0;
    int[] count = new int[MAX + 1];

    for (final int num : nums)
      ++count[num];

    for (int i = k + 1; i <= MAX; ++i)
      ans += count[i] * count[i - k];

    return ans;
  }
}
