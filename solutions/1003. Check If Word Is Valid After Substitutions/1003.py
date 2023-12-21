class Solution:
  def isValid(self, s: str) -> bool:
    stack = []

    for c in s:
      if c == 'c':
        if len(stack) < 2 or stack[-2] != 'a' or stack[-1] != 'b':
          return False
        stack.pop()
        stack.pop()
      else:
        stack.append(c)

    return not stack
