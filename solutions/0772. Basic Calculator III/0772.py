class Solution:
  def calculate(self, s: str) -> int:
    nums = []
    ops = []

    def calc():
      b = nums.pop()
      a = nums.pop()
      op = ops.pop()
      if op == '+':
        nums.append(a + b)
      elif op == '-':
        nums.append(a - b)
      elif op == '*':
        nums.append(a * b)
      else:  # op == '/'
        nums.append(int(a / b))

    def precedes(prev: str, curr: str) -> bool:
      """
      Returns True if the previous character is a operator and the priority of
      the previous operator >= the priority of the current character (operator).
      """
      if prev == '(':
        return False
      return prev in '*/' or curr in '+-'

    i = 0
    hasPrevNum = False

    while i < len(s):
      c = s[i]
      if c.isdigit():
        num = ord(c) - ord('0')
        while i + 1 < len(s) and s[i + 1].isdigit():
          num = num * 10 + (ord(s[i + 1]) - ord('0'))
          i += 1
        nums.append(num)
        hasPrevNum = True
      elif c == '(':
        ops.append('(')
        hasPrevNum = False
      elif c == ')':
        while ops[-1] != '(':
          calc()
        ops.pop()  # Pop '('
      elif c in '+-*/':
        if not hasPrevNum:  # Handle input like "-1-(-1)"
          num.append(0)
        while ops and precedes(ops[-1], c):
          calc()
        ops.append(c)
      i += 1

    while ops:
      calc()

    return nums.pop()
