class Solution {
  public int maxSum(int[] nums1, int[] nums2) {
    final int kMod = 1_000_000_007;
    // Keep running sum of nums1 and nums2 before next rendezvous
    // Because nums1 and nums2 are increasing, move forward on the smaller one
    // To ensure we don't miss any rendezvous
    // When meet rendezvous, choose the better path
    long ans = 0;
    long sum1 = 0; // Sum of nums1 in (prev rendezvous, next rendezvous)
    long sum2 = 0; // Sum of nums2 in (prev rendezvous, next rendezvous)
    int i = 0;     // nums1's index
    int j = 0;     // nums2's index

    while (i < nums1.length && j < nums2.length)
      if (nums1[i] < nums2[j]) {
        sum1 += nums1[i++];
      } else if (nums1[i] > nums2[j]) {
        sum2 += nums2[j++];
      } else { // Rendezvous
        ans += Math.max(sum1, sum2) + nums1[i];
        sum1 = 0;
        sum2 = 0;
        ++i;
        ++j;
      }

    while (i < nums1.length)
      sum1 += nums1[i++];

    while (j < nums2.length)
      sum2 += nums2[j++];

    return (int) ((ans + Math.max(sum1, sum2)) % kMod);
  }
}
