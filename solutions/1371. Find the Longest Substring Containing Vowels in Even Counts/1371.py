class Solution:
  def findTheLongestSubstring(self, s: str) -> int:
    VOWELS = 'aeiou'
    ans = 0
    prefix = 0  # the binary prefix
    prefixToIndex = {0: -1}

    for i, c in enumerate(s):
      index = VOWELS.find(c)
      if index != -1:
        prefix ^= 1 << index
      prefixToIndex.setdefault(prefix, i)
      ans = max(ans, i - prefixToIndex[prefix])

    return ans
