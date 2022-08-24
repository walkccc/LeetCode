class Solution:
  def calculate(self, s: str) -> int:
    ans = 0
    prevNum = 0
    currNum = 0
    op = '+'

    for i, c in enumerate(s):
      if c.isdigit():
        currNum = currNum * 10 + int(c)
      if not c.isdigit() and c != ' ' or i == len(s) - 1:
        if op == '+' or op == '-':
          ans += prevNum
          prevNum = currNum if op == '+' else -currNum
        elif op == '*':
          prevNum = prevNum * currNum
        elif op == '/':
          if prevNum < 0:
            prevNum = ceil(prevNum / currNum)
          else:
            prevNum = prevNum // currNum
        op = c
        currNum = 0

    return ans + prevNum
