class Solution {
  public long minOperations(int[] nums1, int[] nums2, int k) {
    if (k == 0)
      return Arrays.equals(nums1, nums2) ? 0 : -1;

    long ans = 0;
    long opsDiff = 0; // the number of increments - the number of decrements

    for (int i = 0; i < nums1.length; ++i) {
      final int diff = nums1[i] - nums2[i];
      if (diff == 0)
        continue;
      if (diff % k != 0)
        return -1;
      final int ops = diff / k;
      opsDiff += ops;
      ans += Math.abs(ops);
    }

    return opsDiff == 0 ? ans / 2 : -1;
  }
}
