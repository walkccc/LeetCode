class Solution:
  def findTheLongestSubstring(self, s: str) -> int:
    ans = 0
    prefix = 0  # binary prefix
    prefixToIndex = {0: -1}

    for i, c in enumerate(s):
      index = 'aeiou'.find(c)
      if index != -1:
        prefix ^= 1 << index
      prefixToIndex.setdefault(prefix, i)
      ans = max(ans, i - prefixToIndex[prefix])

    return ans
