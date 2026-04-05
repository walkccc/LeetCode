class Solution {
  public int numTriplets(int[] nums1, int[] nums2) {
    return countTriplets(nums1, nums2) + countTriplets(nums2, nums1);
  }

  // Returns the number of triplet (i, j, k) if A[i]^2 == B[j] * B[k].
  private int countTriplets(int[] A, int[] B) {
    int res = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (final int b : B)
      count.merge(b, 1, Integer::sum);

    for (final int a : A) {
      long target = (long) a * a;
      for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
        final int b = entry.getKey();
        final int freq = entry.getValue();
        if (target % b > 0 || !count.containsKey((int) (target / b)))
          continue;
        if (target / b == b)
          res += freq * (freq - 1);
        else
          res += freq * count.get((int) (target / b));
      }
    }

    return res / 2;
  }
}
