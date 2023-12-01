class Solution:
  def reverseParentheses(self, s: str) -> str:
    stack = []
    ans = []

    for c in s:
      if c == '(':
        stack.append(len(ans))
      elif c == ')':
        # Reverse the corresponding substring between ().
        j = stack.pop()
        ans[j:] = ans[j:][::-1]
      else:
        ans.append(c)

    return ''.join(ans)
