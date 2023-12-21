class Solution:
  def xorOperation(self, n: int, start: int) -> int:
    return functools.reduce(operator.xor,
                            [start + 2 * i for i in range(n)])
