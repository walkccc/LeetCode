class Solution:
  def titleToNumber(self, columnTitle: str) -> int:
    return functools.reduce(lambda subtotal, c:
                            subtotal * 26 + ord(c) - ord('@'), columnTitle, 0)
