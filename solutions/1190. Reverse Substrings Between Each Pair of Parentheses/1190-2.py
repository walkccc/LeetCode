class Solution:
  def reverseParentheses(self, s: str) -> str:
    ans = []
    stack = []
    pair = {}

    for i, c in enumerate(s):
      if c == '(':
        stack.append(i)
      elif c == ')':
        j = stack.pop()
        pair[i] = j
        pair[j] = i

    i = 0
    d = 1
    while i < len(s):
      if s[i] in '()':
        i = pair[i]
        d = -d
      else:
        ans.append(s[i])
      i += d

    return ''.join(ans)
