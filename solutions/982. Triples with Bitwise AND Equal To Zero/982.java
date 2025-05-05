class Solution {
  public int countTriplets(int[] nums) {
    final int MAX = 1 << 16;
    int ans = 0;
    int[] count = new int[MAX]; // {nums[i] & nums[j]: times}

    for (final int a : nums)
      for (final int b : nums)
        ++count[a & b];

    for (final int num : nums)
      for (int i = 0; i < MAX; ++i)
        if ((num & i) == 0)
          ans += count[i];

    return ans;
  }
}
