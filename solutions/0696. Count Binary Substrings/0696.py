class Solution:
  def countBinarySubstrings(self, s: str) -> int:
    ans = 0
    prevCount = 0
    equals = 1

    for i in range(len(s) - 1):
      if s[i] == s[i + 1]:
        equals += 1
      else:
        ans += min(prevCount, equals)
        prevCount = equals
        equals = 1

    return ans + min(prevCount, equals)
