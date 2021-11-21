class Solution:
  def validMountainArray(self, A: List[int]) -> bool:
    if len(A) < 3:
      return False

    l = 0
    r = len(A) - 1

    while l + 1 < len(A) and A[l] < A[l + 1]:
      l += 1
    while r > 0 and A[r] < A[r - 1]:
      r -= 1

    return l > 0 and r < len(A) - 1 and l == r
