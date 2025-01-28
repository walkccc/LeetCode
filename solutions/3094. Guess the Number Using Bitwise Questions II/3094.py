# Definition of commonBits API.
# def commonBits(num: int) -> int:

class Solution:
  def findNumber(self) -> int:
    ans = 0
    sameCount = commonBits(0)

    for i in range(31):
      if commonBits(1 << i) > sameCount:
        ans |= 1 << i
      commonBits(1 << i)  # Revert the XOR.

    return ans
