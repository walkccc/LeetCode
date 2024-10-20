# Definition of commonSetBits API.
# def commonSetBits(num: int) -> int:

class Solution:
  def findNumber(self) -> int:
    return sum(1 << i for i in range(31)
               if commonSetBits(1 << i) == 1)
