class Solution:
  def longestPrefix(self, s: str) -> str:
    kBase = 26
    kHash = 8_417_508_174_513
    n = len(s)
    maxLength = 0
    pow = 1
    prefixHash = 0  # the hash of s[0..i]
    suffixHash = 0  # the hash of s[j..n)

    def val(c: str) -> int:
      return string.ascii_lowercase.index(c)

    j = n - 1
    for i in range(n - 1):
      prefixHash = (prefixHash * kBase + val(s[i])) % kHash
      suffixHash = (val(s[j]) * pow + suffixHash) % kHash
      pow = pow * kBase % kHash
      if prefixHash == suffixHash:
        maxLength = i + 1
      j -= 1

    return s[:maxLength]
