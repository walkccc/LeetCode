class Solution:
  def maxProduct(self, s: str) -> int:
    kBase = 26
    kHash = 1_000_000_007
    n = len(s)
    pows = [1]  # pows[i] := kBase^i % kHash
    # hashL[i] = the hash of the first i letters of s, where hashL[i] =
    # (26^(i - 1) * s[0] + 26^(i - 2) * s[1] + ... + s[i - 1]) % kHash
    hashL = [0]
    # hashR[i] = the hash of the last i letters of s, where hashR[i] =
    # (26^(i - 1) * s[-1] + 26^(i - 2) * s[-2] + ... + s[-i]) % kHash
    hashR = [0]
    # maxLeft[i] := the maximum odd length of palindromes in s[0..i]
    maxLeft = [0] * n
    # maxRight[i] := the maximum odd length of palindromes in s[i..n - 1]
    maxRight = [0] * n

    def val(c: str) -> int:
      return string.ascii_lowercase.index(c)

    for _ in range(n):
      pows.append(pows[-1] * kBase % kHash)

    for c in s:
      hashL.append((hashL[-1] * kBase + val(c)) % kHash)

    for c in reversed(s):
      hashR.append((hashR[-1] * kBase + val(c)) % kHash)

    hashR.reverse()

    def getLeftRollingHash(l: int, r: int) -> int:
      """Returns the left rolling hash of s[l..r)."""
      h = (hashL[r] - hashL[l] * pows[r - l]) % kHash
      return h + kHash if h < 0 else h

    def getRightRollingHash(l: int, r: int) -> int:
      """Returns the right rolling hash of s[l..r)."""
      h = (hashR[l] - hashR[r] * pows[r - l]) % kHash
      return h + kHash if h < 0 else h

    def isPalindrome(l: int, r: int) -> bool:
      """Returns True if s[l..r) is a palindrome."""
      return getLeftRollingHash(l, r) == getRightRollingHash(l, r)

    maxLength = 1
    for r in range(n):
      l = (r - maxLength - 2) + 1
      if l >= 0 and isPalindrome(l, r + 1):
        maxLength += 2
      maxLeft[r] = maxLength

    maxLength = 1
    for l in reversed(range(n)):
      r = (l + maxLength + 2) - 1
      if r < n and isPalindrome(l, r + 1):
        maxLength += 2
      maxRight[l] = maxLength

    return max(maxLeft[i - 1] * maxRight[i] for i in range(1, n))
