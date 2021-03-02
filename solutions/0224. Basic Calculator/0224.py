class Solution:
  def calculate(self, s: str) -> int:
    ans = 0
    num = 0
    sign = 1
    stack = [sign]

    for i, c in enumerate(s):
      if c.isdigit():
        num = num * 10 + ord(c) - ord('0')
      elif c in '+-':
        ans += sign * num
        sign = stack[-1] * (1 if c == '+' else -1)
        num = 0
      elif c == '(':
        stack.append(sign)
      elif c == ')':
        stack.pop()

    return ans + sign * num
