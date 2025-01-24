class Solution:
  def countDigits(self, num: int) -> int:
    return sum(num % int(d) == 0 for d in str(num))
