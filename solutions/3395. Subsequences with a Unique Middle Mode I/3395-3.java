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
      ss = (ss + (long) freq * freq) % kMod;

    for (int i = 0; i < nums.length; ++i) {
      final int a = nums[i];
      long sa = s.get(a);
      final long pa = p.getOrDefault(a, 0);

      // Update running sums after decrementing s[a]
      pss = (pss + pa * (-sa * sa + (sa - 1) * (sa - 1))) % kMod;
      spp = (spp - pa * pa) % kMod; // (-sa + (sa - 1)) * pa * pa
      ss = (ss - sa * sa + (sa - 1) * (sa - 1)) % kMod;
      ps = (ps - pa) % kMod; // -pa * (-sa + (sa - 1))

      s.merge(a, -1, Integer::sum);
      sa = s.get(a);

      final int l = i;
      final int r = nums.length - i - 1;

      // Start with all possible subsequences with `a` as the middle number
      ans = (int) ((ans + (long) nC2(l) * nC2(r)) % kMod);

      // Minus cases where frequency of `a` is 1, so it's not a mode
      ans = (int) ((ans - (long) nC2(l - pa) * nC2(r - sa)) % kMod);

      // Minus the values where `b != a`
      final long pss_ = (pss - pa * sa * sa) % kMod;
      final long spp_ = (spp - sa * pa * pa) % kMod;
      final long pp_ = (pp - pa * pa) % kMod;
      final long ss_ = (ss - sa * sa) % kMod;
      final long ps_ = (ps - pa * sa) % kMod;
      final long p_ = l - pa;
      final long s_ = r - sa;

      // Minus cases where `a` is not a "unique" mode or not a mode
      long subtract = 0;
      subtract = (subtract + ps_ * (pa * (r - sa))) % kMod;
      subtract = (subtract + pss_ * (-pa)) % kMod;
      subtract = (subtract + ps_ * (sa * (l - pa))) % kMod;
      subtract = (subtract + spp_ * (-sa)) % kMod;
      subtract = (subtract + (pp_ - p_) * sa * (r - sa) / 2) % kMod;
      subtract = (subtract + (ss_ - s_) * pa * (l - pa) / 2) % kMod;
      ans = (int) ((ans - subtract + kMod) % kMod);

      // Update running sums after incrementing p[a]
      pss = (pss + sa * sa) % kMod; // (-pa + (pa + 1)) * sa * sa
      spp = (spp + sa * (-pa * pa + (pa + 1) * (pa + 1))) % kMod;
      pp = (pp - pa * pa + (pa + 1) * (pa + 1)) % kMod;
      ps = (ps + sa) % kMod; // (-pa + (pa + 1)) * sa

      p.merge(a, 1, Integer::sum);
    }

    return (int) ((ans + kMod) % kMod);
  }

  private static final int kMod = 1_000_000_007;

  // Returns C(n, 2)
  private long nC2(long n) {
    return n * (n - 1) / 2 % kMod;
  }
}
