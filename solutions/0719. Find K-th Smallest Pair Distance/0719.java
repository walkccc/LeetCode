class Solution {
  public int smallestDistancePair(int[] nums, int k) {
    Arrays.sort(nums);

    int l = 0;
    int r = nums[nums.length - 1] - nums[0];

    while (l < r) {
      final int m = (l + r) / 2;
      if (pairDistancesNoGreaterThan(nums, m) >= k)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  private int pairDistancesNoGreaterThan(int[] nums, int m) {
    int count = 0;
    int j = 1;
    // for each index i, find the first index j s.t. nums[j] > nums[i] + m,
    // so pairDistancesNoGreaterThan for index i will be j - i - 1
    for (int i = 0; i < nums.length; ++i) {
      while (j < nums.length && nums[j] <= nums[i] + m)
        ++j;
      count += j - i - 1;
    }
    return count;
  }
}
