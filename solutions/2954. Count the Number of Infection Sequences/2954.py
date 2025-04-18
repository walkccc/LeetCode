class Solution:
  def numberOfSequence(self, n: int, sick: list[int]) -> int:
    MOD = 1_000_000_007

    @functools.lru_cache(None)
    def fact(i: int) -> int:
      return 1 if i <= 1 else i * fact(i - 1) % MOD

    @functools.lru_cache(None)
    def inv(i: int) -> int:
      return pow(i, MOD - 2, MOD)

    ans = fact(n - len(sick))  # the number of infected children
    prevSick = -1

    for i, s in enumerate(sick):
      # The segment [prevSick + 1, sick - 1] are the current non-infected
      # children.
      nonInfected = sick[i] - prevSick - 1
      prevSick = sick[i]
      if nonInfected == 0:
        continue
      ans *= inv(fact(nonInfected))
      ans %= MOD
      if i > 0:
        # There're two choices per second since the children at the two
        # endpoints can both be the infect candidates. So, there are
        # 2^[nonInfected - 1] ways to infect all children in the current
        # segment.
        ans *= pow(2, nonInfected - 1, MOD)

    nonInfected = n - sick[-1] - 1
    return ans * inv(fact(nonInfected)) % MOD
