class Solution:
  def addDigits(self, num: int) -> int:
    return 0 if num == 0 else 1 + (num - 1) % 9
