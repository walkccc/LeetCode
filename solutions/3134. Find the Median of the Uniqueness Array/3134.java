class Solution {
  public int medianOfUniquenessArray(int[] nums) {
    final int n = nums.length;
    final long subarrayCount = n * (n + 1L) / 2;
    final long medianCount = (subarrayCount + 1) / 2;
    int l = 1;
    int r = n;

    while (l < r) {
      final int m = (l + r) / 2;
      if (subarrayWithAtMostKDistinct(nums, m) >= medianCount)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  // Similar to 992. Subarrays with K Different Integers
  private long subarrayWithAtMostKDistinct(int[] nums, int k) {
    long res = 0;
    HashMap<Integer, Integer> count = new HashMap<>();

    for (int l = 0, r = 0; r < nums.length; ++r) {
      if (count.merge(nums[r], 1, Integer::sum) == 1)
        --k;
      while (k == -1)
        if (count.merge(nums[l++], -1, Integer::sum) == 0)
          ++k;
      res += r - l + 1; // nums[l..r], nums[l + 1..r], ..., nums[r]
    }

    return res;
  }
}
