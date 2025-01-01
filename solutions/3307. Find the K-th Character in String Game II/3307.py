class Solution:
  def kthCharacter(self, k: int, operations: list[int]) -> str:
    operationsCount = math.ceil(math.log2(k))
    increases = 0

    for i in range(operationsCount - 1, -1, -1):
      halfSize = 2**i
      if k > halfSize:
        k -= halfSize  # Move k from the right half to the left half.
        increases += operations[i]

    return string.ascii_lowercase[increases % 26]
