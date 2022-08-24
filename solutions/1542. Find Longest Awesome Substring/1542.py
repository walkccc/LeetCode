class Solution:
  def longestAwesome(self, s: str) -> int:
    ans = 0
    prefix = 0  # binary prefix
    prefixToIndex = [len(s)] * 1024
    prefixToIndex[0] = -1

    for i, c in enumerate(s):
      prefix ^= 1 << ord(c) - ord('0')
      ans = max(ans, i - prefixToIndex[prefix])
      for j in range(10):
        ans = max(ans, i - prefixToIndex[prefix ^ 1 << j])
      prefixToIndex[prefix] = min(prefixToIndex[prefix], i)

    return ans
