class Solution:
  def countDistinct(self, s: str) -> int:
    kBase = 26
    kHash = 1_000_000_007

    n = len(s)
    ans = 0
    pow = [1] + [0] * n     # pow[i] := kBase^i
    hashes = [0] * (n + 1)  # hashes[i] := the hash of s[0..i)

    def val(c: str) -> int:
      return string.ascii_lowercase.index(c)

    for i in range(1, n + 1):
      pow[i] = pow[i - 1] * kBase % kHash
      hashes[i] = (hashes[i - 1] * kBase + val(s[i - 1])) % kHash

    def getHash(l: int, r: int) -> int:
      """Returns the hash of s[l..r)."""
      hash = (hashes[r] - hashes[l] * pow[r - l]) % kHash
      return hash + kHash if hash < 0 else hash

    for length in range(1, n + 1):
      seen = set()
      for i in range(n - length + 1):
        seen.add(getHash(i, i + length))
      ans += len(seen)

    return ans
