class Solution:
  def maxDepth(self, s: str) -> int:
    ans = 0
    opened = 0

    for c in s:
      if c == '(':
        opened += 1
        ans = max(ans, opened)
      elif c == ')':
        opened -= 1

    return ans
