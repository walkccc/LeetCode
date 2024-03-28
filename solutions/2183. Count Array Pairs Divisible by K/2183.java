class Solution {
  public long countPairs(int[] nums, int k) {
    long ans = 0;
    Map<Long, Integer> gcds = new HashMap<>();

    for (final int num : nums) {
      final long gcd_i = gcd(num, k);
      for (final long gcd_j : gcds.keySet())
        if (gcd_i * gcd_j % k == 0)
          ans += gcds.get(gcd_j);
      gcds.merge(gcd_i, 1, Integer::sum);
    }

    return ans;
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
