class Solution {
  public int countTriplets(int[] nums) {
    final int kMax = 1 << 16;
    int ans = 0;
    int[] count = new int[kMax]; // {nums[i] & nums[j]: times}

    for (final int a : nums)
      for (final int b : nums)
        ++count[a & b];

    for (final int num : nums)
      for (int i = 0; i < kMax; ++i)
        if ((num & i) == 0)
          ans += count[i];

    return ans;
  }
}
