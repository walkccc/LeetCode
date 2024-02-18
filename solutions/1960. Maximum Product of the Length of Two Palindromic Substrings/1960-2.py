class Solution:
  def maxProduct(self, s: str) -> int:
    kBase = 26
    kMod = 1_000_000_007
    n = len(s)
    ans = 1
    pow = [1] + [0] * n  # pow[i] := kBase^i
    hashFromL = [0] * (n + 1)  # hashFromL[i] = the hash of s[0..i)
    hashFromR = [0] * (n + 1)  # hashFromR[i] = the hash of s[i..n)
    l = [0] * n  # l[i] := the maximum length of palindromes in s[0..i)
    r = [0] * n  # r[i] := the maximum length of palindromes in s[i..n)

    for i in range(1, n + 1):
      pow[i] = pow[i - 1] * kBase % kMod

    def val(c: str) -> int:
      return ord(c) - ord('a')

    for i in range(1, n + 1):
      hashFromL[i] = (hashFromL[i - 1] * kBase + val(s[i - 1])) % kMod

    for i in reversed(range(n)):
      hashFromR[i] = (hashFromR[i + 1] * kBase + val(s[i])) % kMod

    # Returns the hash of s[l..r) from the left.
    def leftHash(l: int, r: int) -> int:
      hash = (hashFromL[r] - hashFromL[l] * pow[r - l]) % kMod
      return hash + kMod if hash < 0 else hash

    # Returns the hash of s[l..r) from the right.
    def rightHash(l: int, r: int) -> int:
      hash = (hashFromR[l] - hashFromR[r] * pow[r - l]) % kMod
      return hash + kMod if hash < 0 else hash

    # Returns true if s[l..r) is a palindrome.
    def isPalindrome(l: int, r: int) -> bool:
      return leftHash(l, r) == rightHash(l, r)

    maxi = 1  # the maximum length of palindromes so far
    for i in range(n):
      if i - maxi - 1 >= 0 and isPalindrome(i - maxi - 1, i + 1):
        maxi += 2
      l[i] = maxi

    # Fill in r.
    maxi = 1
    for i in reversed(range(n)):
      if i + maxi + 2 <= n and isPalindrome(i, i + maxi + 2):
        maxi += 2
      r[i] = maxi

    for i in range(n - 1):
      ans = max(ans, l[i] * r[i + 1])

    return ans
