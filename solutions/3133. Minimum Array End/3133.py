class Solution:
  def minEnd(self, n: int, x: int) -> int:
    # Set x's 0s with (n - 1)'s LSb-to-MSb bits, preserving x's 1s. This
    # operation increase x for (n - 1) iterations while preserving x's 1s.
    MAX_BIT = n.bit_length() + x.bit_length()
    k = n - 1
    BINARY_INDEX = 0

    for i in range(MAX_BIT):
      if x >> i & 1 == 0:
        # Set x's 0 with k's bit if the running bit of k is 1.
        if k >> BINARY_INDEX & 1:
          x |= 1 << i
        BINARY_INDEX += 1

    return x
