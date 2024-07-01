class Solution:
  def maxNumber(self, n: int) -> int:
    # assume n = 0b00...11???
    #        x = 0b00...01111
    #  since y = 0b00...10000 is in [x, n]
    #    and x & y = 0
    return (1 << n.bit_length() - 1) - 1
