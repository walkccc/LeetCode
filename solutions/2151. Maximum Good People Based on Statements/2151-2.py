class Solution:
  def maximumGood(self, statements: list[list[int]]) -> int:
    n = len(statements)

    def isValid(mask: int) -> bool:
      for i in range(n):
        # The i-th person is bad, so no need to check.
        if (mask >> i & 1) == 0:
          continue
        for j in range(n):
          if statements[i][j] == 2:
            continue
          if statements[i][j] != (mask >> j & 1):
            return False
      return True

    return max(mask.bit_count()
               for mask in range(1 << n)
               if isValid(mask))
