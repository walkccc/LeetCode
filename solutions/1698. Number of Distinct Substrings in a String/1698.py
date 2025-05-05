class Solution:
  def countDistinct(self, s: str) -> int:
    BASE = 26
    HASH = 1_000_000_007

    n = len(s)
    ans = 0
    pow = [1] + [0] * n     # pow[i] := BASE^i
    hashes = [0] * (n + 1)  # hashes[i] := the hash of s[0..i)

    def val(c: str) -> int:
      return ord(c) - ord('a')

    for i in range(1, n + 1):
      pow[i] = pow[i - 1] * BASE % HASH
      hashes[i] = (hashes[i - 1] * BASE + val(s[i - 1])) % HASH

    def getHash(l: int, r: int) -> int:
      """Returns the hash of s[l..r)."""
      hash = (hashes[r] - hashes[l] * pow[r - l]) % HASH
      return hash + HASH if hash < 0 else hash

    for length in range(1, n + 1):
      seen = set()
      for i in range(n - length + 1):
        seen.add(getHash(i, i + length))
      ans += len(seen)

    return ans
