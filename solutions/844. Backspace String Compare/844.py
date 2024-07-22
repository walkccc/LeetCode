class Solution:
  def backspaceCompare(self, s: str, t: str) -> bool:
    def backspace(s: str) -> str:
      stack = []
      for c in s:
        if c != '#':
          stack.append(c)
        elif stack:
          stack.pop()
      return stack

    return backspace(s) == backspace(t)
