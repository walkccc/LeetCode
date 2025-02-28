class Solution:
  def removeOuterParentheses(self, s: str) -> str:
    ans = []
    opened = 0

    for c in s:
      if c == '(':
        opened += 1
        if opened > 1:
          ans.append(c)
      else:  # c == ')'
        opened -= 1
        if opened > 0:
          ans.append(c)

    return ''.join(ans)
