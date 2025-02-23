class Solution:
  def makeStringSorted(self, s: str) -> int:
    kMod = 1_000_000_007
    ans = 0
    count = [0] * 26

    @functools.lru_cache(None)
    def fact(i: int) -> int:
      return 1 if i <= 1 else i * fact(i - 1) % kMod

    @functools.lru_cache(None)
    def inv(i: int) -> int:
      return pow(i, kMod - 2, kMod)

    for i, c in enumerate(reversed(s)):
      order = ord(c) - ord('a')
      count[order] += 1
      # count[:order] := s[i] can be any character smaller than c
      # fact(i) := s[i + 1..n - 1] can be any sequence of characters
      perm = sum(count[:order]) * fact(i)
      for j in range(26):
        perm = perm * inv(fact(count[j])) % kMod
      ans = (ans + perm) % kMod

    return ans
