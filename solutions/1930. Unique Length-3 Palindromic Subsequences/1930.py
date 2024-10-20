class Solution:
  def countPalindromicSubsequence(self, s: str) -> int:
    ans = 0
    first = [len(s)] * 26
    last = [0] * 26

    for i, c in enumerate(s):
      index = string.ascii_lowercase.index(c)
      first[index] = min(first[index], i)
      last[index] = i

    for f, l in zip(first, last):
      if f < l:
        ans += len(set(s[f + 1:l]))

    return ans
