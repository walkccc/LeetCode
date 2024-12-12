class Solution:
  def scoreOfParentheses(self, s: str) -> int:
    ans = 0
    layer = 0

    for a, b in itertools.pairwise(s):
      if a + b == '()':
        ans += 1 << layer
      layer += 1 if a == '(' else -1

    return ans
