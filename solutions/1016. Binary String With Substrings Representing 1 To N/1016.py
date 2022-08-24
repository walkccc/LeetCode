class Solution:
  def queryString(self, S: str, N: int) -> bool:
    if N > 1511:
      return False

    for i in range(N, N // 2, -1):
      if format(i, 'b') not in S:
        return False

    return True
