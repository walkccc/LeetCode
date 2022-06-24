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

    # return true if prevOp is a operator and
    # priority(prevOp) >= priority(currOp)
    def precedes(prevOp: chr, currOp: chr) -> bool:
      if prevOp == '(':
        return False
      return prevOp in '*/' or currOp in '+-'

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
        ops.pop()  # pop '('
      elif c in '+-*/':
        if not hasPrevNum:  # handle input like "-1-(-1)"
          num.append(0)
        while ops and precedes(ops[-1], c):
          calc()
        ops.append(c)
      i += 1

    while ops:
      calc()

    return nums.pop()
