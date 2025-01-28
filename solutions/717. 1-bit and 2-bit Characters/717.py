class Solution:
  def isOneBitCharacter(self, bits: list[int]) -> bool:
    i = 0
    while i < len(bits) - 1:
      i += bits[i] + 1

    return i == len(bits) - 1
