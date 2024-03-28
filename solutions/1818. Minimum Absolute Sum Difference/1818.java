class Solution {
  public int minAbsoluteSumDiff(int[] nums1, int[] nums2) {
    final int kMod = 1_000_000_007;
    long sumDiff = 0;
    long maxDecrement = 0;
    TreeSet<Integer> sorted = new TreeSet<>();

    for (final int num : nums1)
      sorted.add(num);

    for (int i = 0; i < nums1.length; ++i) {
      final long currDiff = (long) Math.abs(nums1[i] - nums2[i]);
      sumDiff += currDiff;
      Integer ceiling = sorted.ceiling(nums2[i]);
      Integer floor = sorted.floor(nums2[i]);
      if (ceiling != null)
        maxDecrement = Math.max(maxDecrement, currDiff - (long) Math.abs(ceiling - nums2[i]));
      if (floor != null)
        maxDecrement = Math.max(maxDecrement, currDiff - (long) Math.abs(floor - nums2[i]));
    }

    return (int) ((sumDiff - maxDecrement) % kMod);
  }
}
