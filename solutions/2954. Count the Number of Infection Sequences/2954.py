class Solution:
  def numberOfSequence(self, n: int, sick: List[int]) -> int:
    kMod = 1_000_000_007

    @functools.lru_cache(None)
    def fact(i: int) -> int:
      return 1 if i <= 1 else i * fact(i - 1) % kMod

    @functools.lru_cache(None)
    def inv(i: int) -> int:
      return pow(i, kMod - 2, kMod)

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
      ans %= kMod
      if i > 0:
        # There're two choices per second since the children at the two
        # endpoints can both be the infect candidates. So, there are
        # 2^[nonInfected - 1] ways to infect all children in the current
        # segment.
        ans *= pow(2, nonInfected - 1, kMod)

    nonInfected = n - sick[-1] - 1
    return ans * inv(fact(nonInfected)) % kMod
