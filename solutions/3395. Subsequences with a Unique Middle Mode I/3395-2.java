class Solution {
  public int subsequencesWithMiddleMode(int[] nums) {
    int ans = 0;
    Map<Integer, Integer> p = new HashMap<>(); // prefix counter
    Map<Integer, Integer> s = new HashMap<>(); // suffix counter

    for (final int num : nums)
      s.merge(num, 1, Integer::sum);

    for (int i = 0; i < nums.length; ++i) {
      final int a = nums[i];
      s.merge(a, -1, Integer::sum);

      final int l = i;
      final int r = nums.length - i - 1;

      final int pa = p.getOrDefault(a, 0);
      final int sa = s.get(a);

      // Start with all possible subsequences with `a` as the middle number.
      ans = (int) ((ans + (long) nC2(l) * nC2(r)) % MOD);

      // Minus cases where frequency of 'a' is 1, so it's not a mode.
      ans = (int) ((ans - (long) nC2(l - pa) * nC2(r - sa)) % MOD);

      for (final int b : getUniqueNums(p, s)) {
        if (b == a)
          continue;

        final int pb = p.getOrDefault(b, 0);
        final int sb = s.get(b);

        // Minus cases where the middle number is not a "unique" mode
        int subtract = 0;

        // [a b] a [b c]
        subtract = (int) ((subtract + (long) pa * pb * sb * (r - sa - sb)) % MOD);

        // [b c] a [a b]
        subtract = (int) ((subtract + (long) sa * sb * pb * (l - pa - pb)) % MOD);

        // [b b] a [a c]
        subtract = (int) ((subtract + (long) nC2(pb) * sa * (r - sa - sb)) % MOD);

        // [a c] a [b b]
        subtract = (int) ((subtract + (long) nC2(sb) * pa * (l - pa - pb)) % MOD);

        // [b b] a [a b]
        subtract = (int) ((subtract + (long) nC2(pb) * sa * sb) % MOD);

        // [a b] a [b b]
        subtract = (int) ((subtract + (long) nC2(sb) * pa * pb) % MOD);

        ans = (int) ((ans - subtract + MOD) % MOD);
      }

      p.merge(a, 1, Integer::sum);
    }

    return (ans + MOD) % MOD;
  }

  private static final int MOD = 1_000_000_007;

  private int nC2(long n) {
    return (int) (n * (n - 1) / 2 % MOD);
  }

  private Set<Integer> getUniqueNums(final Map<Integer, Integer> p, final Map<Integer, Integer> s) {
    final Set<Integer> uniqueNums = new HashSet<>();
    uniqueNums.addAll(p.keySet());
    uniqueNums.addAll(s.keySet());
    return uniqueNums;
  }
}
