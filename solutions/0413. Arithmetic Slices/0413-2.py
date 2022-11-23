class Solution:
  def numberOfArithmeticSlices(self, A: List[int]) -> int:
    ans = 0
    dp = 0

    for i in range(2, len(A)):
      if A[i] - A[i - 1] == A[i - 1] - A[i - 2]:
        dp += 1
        ans += dp
      else:
        dp = 0

    return ans
