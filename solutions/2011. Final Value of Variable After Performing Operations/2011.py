class Solution:
  def finalValueAfterOperations(self, operations: list[str]) -> int:
    return sum(op[1] == '+' or -1 for op in operations)
