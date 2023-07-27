class Solution:
  def minOperations(self, grid: List[List[int]], x: int) -> int:
    A = sorted([a for row in grid for a in row])
    if any((a - A[0]) % x for a in A):
      return -1

    ans = 0

    for a in A:
      ans += abs(a - A[len(A) // 2]) // x

    return ans
