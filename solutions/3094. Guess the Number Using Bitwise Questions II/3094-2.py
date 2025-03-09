# Definition of commonBits API.
# def commonBits(num: int) -> int:

class Solution:
  def findNumber(self) -> int:
    return functools.reduce(lambda x, i: x | (1 << i)
                            if commonBits(1 << i) > commonBits(1 << i)
                            else x, range(31), 0)
