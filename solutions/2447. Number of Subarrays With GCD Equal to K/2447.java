class Solution {
  public int subarrayGCD(int[] nums, int k) {
    int ans = 0;
    Map<Integer, Integer> gcds = new HashMap<>();

    for (final int num : nums)
      if (num % k == 0) {
        Map<Integer, Integer> nextGcds = new HashMap<>();
        nextGcds.put(num, 1);
        for (Map.Entry<Integer, Integer> entry : gcds.entrySet()) {
          final int prevGcd = entry.getKey();
          final int count = entry.getValue();
          nextGcds.merge(gcd(prevGcd, num), count, Integer::sum);
        }
        ans += nextGcds.getOrDefault(k, 0);
        gcds = nextGcds;
      } else {
        // The GCD streak stops, so fresh start from the next number.
        gcds.clear();
      }

    return ans;
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
