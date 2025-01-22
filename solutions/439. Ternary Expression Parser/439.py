class Solution:
  def parseTernary(self, expression: str) -> str:
    c = expression[self.i]

    if self.i + 1 == len(expression) or expression[self.i + 1] == ':':
      self.i += 2
      return str(c)

    self.i += 2
    first = self.parseTernary(expression)
    second = self.parseTernary(expression)

    return first if c == 'T' else second

  i = 0
