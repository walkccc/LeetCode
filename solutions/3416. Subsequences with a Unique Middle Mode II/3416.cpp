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
//   sum(b != a) (p[a] * p * s) * (r - sa - s)
//             + (sa * s * p) * (l - p[a] - p)
//             + (p, 2) * sa * (r - sa)
//             + (s, 2) * p[a] * (l - p[a])
//
//   sum(b != a) (p * s) * (p[a] * (r - sa)) + (p * s^2) * (-p[a])
//             + (s * p) * (sa * (l - p[a])) + (s * p^2) * (-sa)
//             + (p^2 - p) * (sa * (r - sa) / 2)
//             + (s^2 - s) * (p[a] * (l - p[a]) / 2)

class Solution {
 public:
  // Same as 3395. Subsequences with a Unique Middle Mode I
  int subsequencesWithMiddleMode(vector<int>& nums) {
    int ans = 0;
    unordered_map<int, int> p;  // prefix counter
    unordered_map<int, int> s;  // suffix counter

    for (const int num : nums)
      ++s[num];

    long pss = 0;
    long spp = 0;
    long pp = 0;
    long ss = 0;
    long ps = 0;

    for (const auto& [_, freq] : s)
      ss = (ss + static_cast<long>(freq) * freq) % kMod;

    for (int i = 0; i < nums.size(); ++i) {
      const int a = nums[i];
      long sa = s[a];
      const long pa = p[a];

      // Update running sums after decrementing sa.
      pss = (pss + pa * (-sa * sa + (sa - 1) * (sa - 1))) % kMod;
      spp = (spp - pa * pa) % kMod;  // (-sa + (sa - 1)) * pa * pa
      ss = (ss - sa * sa + (sa - 1) * (sa - 1)) % kMod;
      ps = (ps - pa) % kMod;  // -pa * (-sa + (sa - 1))

      sa = --s[a];

      const int l = i;
      const int r = nums.size() - i - 1;

      // Start with all possible subsequences with `a` as the middle number.
      ans = (ans + nC2(l) * nC2(r)) % kMod;

      // Minus cases where frequency of `a` is 1, so it's not a mode.
      ans = (ans - nC2(l - pa) * nC2(r - sa)) % kMod;

      // Minus the values where `b != a`.
      const long pss_ = (pss - pa * sa * sa) % kMod;
      const long spp_ = (spp - sa * pa * pa) % kMod;
      const long pp_ = (pp - pa * pa) % kMod;
      const long ss_ = (ss - sa * sa) % kMod;
      const long ps_ = (ps - pa * sa) % kMod;
      const long p_ = l - pa;
      const long s_ = r - sa;

      // Minus cases where `a` is not a "unique" mode or not a mode.
      long subtract = 0;
      subtract = (subtract + ps_ * (pa * (r - sa))) % kMod;
      subtract = (subtract + pss_ * (-pa)) % kMod;
      subtract = (subtract + ps_ * (sa * (l - pa))) % kMod;
      subtract = (subtract + spp_ * (-sa)) % kMod;
      subtract = (subtract + (pp_ - p_) * sa * (r - sa) / 2) % kMod;
      subtract = (subtract + (ss_ - s_) * pa * (l - pa) / 2) % kMod;
      ans = (ans - subtract + kMod) % kMod;

      // Update running sums after incrementing p[a].
      pss = (pss + sa * sa) % kMod;  // (-pa + (pa + 1)) * sa * sa
      spp = (spp + sa * (-pa * pa + (pa + 1) * (pa + 1))) % kMod;
      pp = (pp - pa * pa + (pa + 1) * (pa + 1)) % kMod;
      ps = (ps + sa) % kMod;  // (-pa + (pa + 1)) * sa

      ++p[a];
    }

    return (ans + kMod) % kMod;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns C(n, 2)
  long nC2(long n) {
    return n * (n - 1) / 2 % kMod;
  }
};
