class Solution:
  def subsequencesWithMiddleMode(self, nums: list[int]) -> int:
    MOD = 1_000_000_007
    ans = 0
    p = collections.Counter()  # prefix counter
    s = collections.Counter(nums)  # suffix counter

    def nC2(n: int) -> int:
      return n * (n - 1) // 2

    for i, a in enumerate(nums):
      s[a] -= 1

      l = i
      r = len(nums) - i - 1

      # Start with all possible subsequences with `a` as the middle number.
      ans += nC2(l) * nC2(r)

      # Minus the cases where the frequency of `a` is 1, so it's not a mode.
      ans -= nC2(l - p[a]) * nC2(r - s[a])

      for b in p | s:
        if b == a:
          continue

        # Minus the cases where the middle number is not a "unique" mode.
        ans -= p[a] * p[b] * s[b] * (r - s[a] - s[b])  # [a b] a [b c]
        ans -= s[a] * s[b] * p[b] * (l - p[a] - p[b])  # [b c] a [a b]
        ans -= nC2(p[b]) * s[a] * (r - s[a] - s[b])  # [b b] a [a c]
        ans -= nC2(s[b]) * p[a] * (l - p[a] - p[b])  # [a c] a [b b]

        # Minus the cases where the middle number is not a mode.
        ans -= nC2(p[b]) * s[a] * s[b]  # [b b] a [a b]
        ans -= nC2(s[b]) * p[a] * p[b]  # [a b] a [b b]

      ans %= MOD
      p[a] += 1

    return ans
