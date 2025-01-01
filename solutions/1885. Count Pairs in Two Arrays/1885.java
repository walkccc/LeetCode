class Solution {
  public long countPairs(int[] nums1, int[] nums2) {
    long ans = 0;
    int[] A = new int[nums1.length]; // A[i] = nums1[i] - nums2[i]

    for (int i = 0; i < A.length; ++i)
      A[i] = nums1[i] - nums2[i];

    Arrays.sort(A);

    for (int i = 0; i < A.length; ++i) {
      final int index = firstGreater(A, -A[i]);
      ans += A.length - Math.max(i + 1, index);
    }

    return ans;
  }

  private int firstGreater(int[] A, int target) {
    int l = 0;
    int r = A.length;
    while (l < r) {
      final int m = (l + r) / 2;
      if (A[m] > target)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
}
