class Solution:
  def calculateTax(self, brackets: list[list[int]], income: int) -> float:
    ans = 0
    prev = 0

    for upper, percent in brackets:
      if income < upper:
        return ans + (income - prev) * percent / 100.0
      ans += (upper - prev) * percent / 100.0
      prev = upper

    return ans
