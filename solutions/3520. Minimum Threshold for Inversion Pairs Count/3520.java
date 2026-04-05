class Solution {
  public int minThreshold(int[] nums, int k) {
    final int mx = Arrays.stream(nums).max().getAsInt();
    int l = 0;
    int r = mx + 1;

    while (l < r) {
      final int m = (l + r) / 2;
      if (countInversionPairs(nums, k, m))
        r = m;
      else
        l = m + 1;
    }

    return l > mx ? -1 : l;
  }

  private boolean countInversionPairs(final int[] nums, final int k, final int threshold) {
    int inversionCount = 0;
    List<Integer> sortedNums = new ArrayList<>();

    for (final int num : nums) {
      final int lower = firstGreater(sortedNums, num);
      final int upper = firstGreater(sortedNums, num + threshold);
      inversionCount += upper - lower;
      sortedNums.add(lower, num);
    }

    return inversionCount >= k;
  }

  private int firstGreater(List<Integer> arr, int target) {
    int l = 0;
    int r = arr.size();
    while (l < r) {
      final int m = (l + r) / 2;
      if (arr.get(m) > target)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
}
