class Solution {
  public long kthSmallestProduct(int[] nums1, int[] nums2, long k) {
    List<Integer> A1 = new ArrayList<>();
    List<Integer> A2 = new ArrayList<>();
    List<Integer> B1 = new ArrayList<>();
    List<Integer> B2 = new ArrayList<>();

    seperate(nums1, A1, A2);
    seperate(nums2, B1, B2);

    final long negCount = A1.size() * B2.size() + A2.size() * B1.size();
    int sign = 1;

    if (k > negCount) {
      k -= negCount; //  Find (k - negCount)-th positive.
    } else {
      k = negCount - k + 1; // Find (negCount - k + 1)-th abs(negative).
      sign = -1;
      List<Integer> temp = B1;
      B1 = B2;
      B2 = temp;
    }

    long l = 0;
    long r = (long) 1e10;

    while (l < r) {
      final long m = (l + r) / 2;
      if (numProductNoGreaterThan(A1, B1, m) + numProductNoGreaterThan(A2, B2, m) >= k)
        r = m;
      else
        l = m + 1;
    }

    return sign * l;
  }

  private void seperate(int[] A, List<Integer> A1, List<Integer> A2) {
    for (final int a : A)
      if (a < 0)
        A1.add(-a);
      else
        A2.add(a);
    Collections.reverse(A1); // Reverse to sort ascending
  }

  private long numProductNoGreaterThan(List<Integer> A, List<Integer> B, long m) {
    long count = 0;
    int j = B.size() - 1;
    // For each a, find the first index j s.t. a * B[j] <= m
    // So numProductNoGreaterThan m for this row will be j + 1
    for (final long a : A) {
      while (j >= 0 && a * B.get(j) > m)
        --j;
      count += j + 1;
    }
    return count;
  }
}
