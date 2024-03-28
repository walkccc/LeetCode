class Solution:
  def doesValidArrayExist(self, derived: List[int]) -> bool:
    return functools.reduce(operator.xor, derived) == 0
