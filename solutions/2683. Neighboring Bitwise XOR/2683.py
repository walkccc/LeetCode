class Solution:
  def doesValidArrayExist(self, derived: list[int]) -> bool:
    return functools.reduce(operator.xor, derived) == 0
