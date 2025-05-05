class Solution:
  def longestPrefix(self, s: str) -> str:
    BASE = 26
    HASH = 8_417_508_174_513
    n = len(s)
    maxLength = 0
    pow = 1
    prefixHash = 0  # the hash of s[0..i]
    suffixHash = 0  # the hash of s[j..n)

    def val(c: str) -> int:
      return ord(c) - ord('a')

    j = n - 1
    for i in range(n - 1):
      prefixHash = (prefixHash * BASE + val(s[i])) % HASH
      suffixHash = (val(s[j]) * pow + suffixHash) % HASH
      pow = pow * BASE % HASH
      if prefixHash == suffixHash:
        maxLength = i + 1
      j -= 1

    return s[:maxLength]
