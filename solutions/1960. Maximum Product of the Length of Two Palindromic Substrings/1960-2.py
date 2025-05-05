class Solution:
  def maxProduct(self, s: str) -> int:
    BASE = 26
    HASH = 1_000_000_007
    n = len(s)
    pows = [1]  # pows[i] := BASE^i % HASH
    # hashL[i] = the hash of the first i letters of s, where hashL[i] =
    # (26^(i - 1) * s[0] + 26^(i - 2) * s[1] + ... + s[i - 1]) % HASH
    hashL = [0]
    # hashR[i] = the hash of the last i letters of s, where hashR[i] =
    # (26^(i - 1) * s[-1] + 26^(i - 2) * s[-2] + ... + s[-i]) % HASH
    hashR = [0]
    # maxLeft[i] := the maximum odd length of palindromes in s[0..i]
    maxLeft = [0] * n
    # maxRight[i] := the maximum odd length of palindromes in s[i..n - 1]
    maxRight = [0] * n

    def val(c: str) -> int:
      return ord(c) - ord('a')

    for _ in range(n):
      pows.append(pows[-1] * BASE % HASH)

    for c in s:
      hashL.append((hashL[-1] * BASE + val(c)) % HASH)

    for c in reversed(s):
      hashR.append((hashR[-1] * BASE + val(c)) % HASH)

    hashR.reverse()

    def getLeftRollingHash(l: int, r: int) -> int:
      """Returns the left rolling hash of s[l..r)."""
      h = (hashL[r] - hashL[l] * pows[r - l]) % HASH
      return h + HASH if h < 0 else h

    def getRightRollingHash(l: int, r: int) -> int:
      """Returns the right rolling hash of s[l..r)."""
      h = (hashR[l] - hashR[r] * pows[r - l]) % HASH
      return h + HASH if h < 0 else h

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
