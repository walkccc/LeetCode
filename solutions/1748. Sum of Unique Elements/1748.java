class Solution {
  public int sumOfUnique(int[] nums) {
    final int kMax = 100;
    int ans = 0;
    int[] count = new int[kMax + 1];

    for (final int num : nums)
      ++count[num];

    for (int i = 1; i <= kMax; ++i)
      if (count[i] == 1)
        ans += i;

    return ans;
  }
}
