class Solution:
  def smallestRepunitDivByK(self, K: int) -> int:
    if K % 10 not in {1, 3, 7, 9}:
      return -1

    seen = set()
    N = 0

    for length in range(1, K + 1):
      N = (N * 10 + 1) % K
      if N == 0:
        return length
      if N in seen:
        return -1
      seen.add(N)

    return -1
