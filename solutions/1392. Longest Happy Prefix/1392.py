class Solution:
  def longestPrefix(self, s: str) -> str:
    kBase = 26
    kMod = 1_000_000_007
    n = len(s)
    maxLength = 0
    pow = 1
    prefixHash = 0  # hash of s[0..i]
    suffixHash = 0  # hash of s[j..n)

    def val(c: str) -> int:
      return ord(c) - ord('a')

    j = n - 1
    for i in range(n - 1):
      prefixHash = (prefixHash * kBase + val(s[i])) % kMod
      suffixHash = (val(s[j]) * pow + suffixHash) % kMod
      pow = pow * kBase % kMod
      if prefixHash == suffixHash:
        maxLength = i + 1
      j -= 1

    return s[:maxLength]
