// Recall from solution 1 that after counting all the subsequences with `a` as
// the middle mode number, we need to subtract the cases where `a` is not a
// unique mode or not a mode.
//
// To avoid the need of looping through all numbers that are not `a`, we can
// maintain the sums that are not related to `a` in the loop.
//
// So, during the simplification of the formula, keep the running sums of
// pss, spp, pp, ss, and ps as the first item.
// (for cleaner notation, abbreviate p[b] and s[b] to just p and s)
//
//   sum(b != a) (p[a] * p * s) * (r - s[a] - s)
//             + (s[a] * s * p) * (l - p[a] - p)
//             + (p, 2) * s[a] * (r - s[a])
//             + (s, 2) * p[a] * (l - p[a])
//
//   sum(b != a) (p * s) * (p[a] * (r - s[a])) + (p * s^2) * (-p[a])
//             + (s * p) * (s[a] * (l - p[a])) + (s * p^2) * (-s[a])
//             + (p^2 - p) * (s[a] * (r - s[a]) / 2)
//             + (s^2 - s) * (p[a] * (l - p[a]) / 2)

class Solution {
  public int subsequencesWithMiddleMode(int[] nums) {
    int ans = 0;
    Map<Integer, Integer> p = new HashMap<>(); // prefix counter
    Map<Integer, Integer> s = new HashMap<>(); // suffix counter

    for (final int num : nums)
      s.merge(num, 1, Integer::sum);

    long pss = 0;
    long spp = 0;
    long pp = 0;
    long ss = 0;
    long ps = 0;

    for (final int freq : s.values())
      ss = (ss + (long) freq * freq) % MOD;

    for (int i = 0; i < nums.length; ++i) {
      final int a = nums[i];
      long sa = s.get(a);
      final long pa = p.getOrDefault(a, 0);

      // Update running sums after decrementing s[a]
      pss = (pss + pa * (-sa * sa + (sa - 1) * (sa - 1))) % MOD;
      spp = (spp - pa * pa) % MOD; // (-sa + (sa - 1)) * pa * pa
      ss = (ss - sa * sa + (sa - 1) * (sa - 1)) % MOD;
      ps = (ps - pa) % MOD; // -pa * (-sa + (sa - 1))

      s.merge(a, -1, Integer::sum);
      sa = s.get(a);

      final int l = i;
      final int r = nums.length - i - 1;

      // Start with all possible subsequences with `a` as the middle number
      ans = (int) ((ans + (long) nC2(l) * nC2(r)) % MOD);

      // Minus cases where frequency of `a` is 1, so it's not a mode
      ans = (int) ((ans - (long) nC2(l - pa) * nC2(r - sa)) % MOD);

      // Minus the values where `b != a`
      final long pss_ = (pss - pa * sa * sa) % MOD;
      final long spp_ = (spp - sa * pa * pa) % MOD;
      final long pp_ = (pp - pa * pa) % MOD;
      final long ss_ = (ss - sa * sa) % MOD;
      final long ps_ = (ps - pa * sa) % MOD;
      final long p_ = l - pa;
      final long s_ = r - sa;

      // Minus cases where `a` is not a "unique" mode or not a mode
      long subtract = 0;
      subtract = (subtract + ps_ * (pa * (r - sa))) % MOD;
      subtract = (subtract + pss_ * (-pa)) % MOD;
      subtract = (subtract + ps_ * (sa * (l - pa))) % MOD;
      subtract = (subtract + spp_ * (-sa)) % MOD;
      subtract = (subtract + (pp_ - p_) * sa * (r - sa) / 2) % MOD;
      subtract = (subtract + (ss_ - s_) * pa * (l - pa) / 2) % MOD;
      ans = (int) ((ans - subtract + MOD) % MOD);

      // Update running sums after incrementing p[a]
      pss = (pss + sa * sa) % MOD; // (-pa + (pa + 1)) * sa * sa
      spp = (spp + sa * (-pa * pa + (pa + 1) * (pa + 1))) % MOD;
      pp = (pp - pa * pa + (pa + 1) * (pa + 1)) % MOD;
      ps = (ps + sa) % MOD; // (-pa + (pa + 1)) * sa

      p.merge(a, 1, Integer::sum);
    }

    return (int) ((ans + MOD) % MOD);
  }

  private static final int MOD = 1_000_000_007;

  // Returns C(n, 2)
  private long nC2(long n) {
    return n * (n - 1) / 2 % MOD;
  }
}
