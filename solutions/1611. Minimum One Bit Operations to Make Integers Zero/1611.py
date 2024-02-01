class Solution:
  def minimumOneBitOperations(self, n: int) -> int:
    # Observation: e.g. n = 2^2
    #        100 (2^2 needs 2^3 - 1 ops)
    # op1 -> 101
    # op2 -> 111
    # op1 -> 110
    # op2 -> 010 (2^1 needs 2^2 - 1 ops)
    # op1 -> 011
    # op2 -> 001 (2^0 needs 2^1 - 1 ops)
    # op1 -> 000
    #
    # So 2^k needs 2^(k + 1) - 1 ops. Note this is reversible, i.e., 0 -> 2^k
    # also takes 2^(k + 1) - 1 ops.

    # e.g. n = 1XXX, our first goal is to change 1XXX -> 1100.
    #   - If the second bit is 1, you only need to consider the cost of turning
    #     the last 2 bits to 0.
    #   - If the second bit is 0, you need to add up the cost of flipping the
    #     second bit from 0 to 1.
    # XOR determines the cost minimumOneBitOperations(1XXX^1100) accordingly.
    # Then, 1100 -> 0100 needs 1 op. Finally, 0100 -> 0 needs 2^3 - 1 ops.
    if n == 0:
      return 0
    # x is the largest 2^k <= n.
    # x | x >> 1 -> x >> 1 needs 1 op.
    #     x >> 1 -> 0      needs x = 2^k - 1 ops.
    x = 1 << n.bit_length() - 1
    return self.minimumOneBitOperations(n ^ (x | x >> 1)) + 1 + x - 1
