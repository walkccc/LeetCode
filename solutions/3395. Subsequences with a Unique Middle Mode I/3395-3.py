# Recall from solution 1 that after counting all the subsequences with `a` as
# the middle mode number, we need to subtract the cases where `a` is not a
# unique mode or not a mode.
#
# To avoid the need of looping through all numbers that are not `a`, we can
# maintain the sums that are not related to `a` in the loop.
#
# So, during the simplification of the formula, keep the running sums of
# pss, spp, pp, ss, and ps as the first item.
# (for cleaner notation, abbreviate p[b] and s[b] to just p and s)
#
#   sum(b != a) (p[a] * p * s) * (r - s[a] - s)
#             + (s[a] * s * p) * (l - p[a] - p)
#             + (p, 2) * s[a] * (r - s[a])
#             + (s, 2) * p[a] * (l - p[a])
#
#   sum(b != a) (p * s) * (p[a] * (r - s[a])) + (p * s^2) * (-p[a])
#             + (s * p) * (s[a] * (l - p[a])) + (s * p^2) * (-s[a])
#             + (p^2 - p) * (s[a] * (r - s[a]) / 2)
#             + (s^2 - s) * (p[a] * (l - p[a]) / 2)


class Solution:
  def subsequencesWithMiddleMode(self, nums: list[int]) -> int:
    MOD = 1_000_000_007
    ans = 0
    p = collections.Counter()  # prefix counter
    s = collections.Counter(nums)  # suffix counter

    def nC2(n: int) -> int:
      return n * (n - 1) // 2

    pss = 0
    spp = 0
    pp = 0
    ss = sum(freq**2 for freq in s.values())
    ps = 0

    for i, a in enumerate(nums):
      # Update running sums after decrementing s[a].
      pss += p[a] * (-s[a]**2 + (s[a] - 1)**2)
      spp += -p[a]**2  # (-s[a] + (s[a] - 1)) * p[a]**2
      ss += -s[a]**2 + (s[a] - 1)**2
      ps += -p[a]  # -p[a] * (-s[a] + (s[a] - 1))

      s[a] -= 1

      l = i
      r = len(nums) - i - 1

      # Start with all possible subsequences with `a` as the middle number.
      ans += nC2(l) * nC2(r)

      # Minus the cases where the frequency of `a` is 1, so it's not a mode.
      ans -= nC2(l - p[a]) * nC2(r - s[a])

      # Minus the values where `b != a`.
      pss_ = pss - p[a] * s[a]**2
      spp_ = spp - s[a] * p[a]**2
      pp_ = pp - p[a]**2
      ss_ = ss - s[a]**2
      ps_ = ps - p[a] * s[a]
      p_ = l - p[a]
      s_ = r - s[a]

      # Minus the cases where the `a` is not a "unique" mode or not a mode.
      ans -= ps_ * (p[a] * (r - s[a])) + pss_ * (-p[a])
      ans -= ps_ * (s[a] * (l - p[a])) + spp_ * (-s[a])
      ans -= (pp_ - p_) * s[a] * (r - s[a]) // 2
      ans -= (ss_ - s_) * p[a] * (l - p[a]) // 2
      ans %= MOD

      # Update running sums after incrementing p[a].
      pss += s[a]**2  # (-p[a] + (p[a] + 1)) * s[a]**2
      spp += s[a] * (-p[a]**2 + (p[a] + 1)**2)
      pp += -p[a]**2 + (p[a] + 1)**2
      ps += s[a]  # (-p[a] + (p[a] + 1)) * s[a]

      p[a] += 1

    return ans
