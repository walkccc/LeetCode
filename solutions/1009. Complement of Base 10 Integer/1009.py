class Solution:
  def bitwiseComplement(self, N: int) -> int:
    mask = 1

    while mask < N:
      mask = (mask << 1) + 1

    return mask ^ N
