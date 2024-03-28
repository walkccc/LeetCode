class Solution:
  def countGoodSubsequences(self, s: str) -> int:
    kMod = 1_000_000_007
    ans = 0
    count = collections.Counter(s)

    @functools.lru_cache(None)
    def fact(i: int) -> int:
      return 1 if i <= 1 else i * fact(i - 1) % kMod

    @functools.lru_cache(None)
    def inv(i: int) -> int:
      return pow(i, kMod - 2, kMod)

    @functools.lru_cache(None)
    def nCk(n: int, k: int) -> int:
      return fact(n) * inv(fact(k)) * inv(fact(n - k)) % kMod

    for freq in range(1, max(count.values()) + 1):
      numSubseqs = 1  # ""
      for charFreq in count.values():
        if charFreq >= freq:
          numSubseqs = numSubseqs * (1 + nCk(charFreq, freq)) % kMod
      ans += numSubseqs - 1  # Minus "".
      ans %= kMod

    return ans
