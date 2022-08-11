class Solution:
  def longestSubsequence(self, s: str, k: int) -> int:
    oneCount = 0
    num = 0
    pow = 1

    # take as many 1s as possible from the right
    for i in reversed(range(len(s))):
      if num + pow > k:
        break
      if s[i] == '1':
        oneCount += 1
        num += pow
      pow *= 2

    return s.count('0') + oneCount
