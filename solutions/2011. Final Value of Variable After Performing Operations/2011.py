class Solution:
  def finalValueAfterOperations(self, operations: List[str]) -> int:
    return sum(op[1] == '+' or -1 for op in operations)
