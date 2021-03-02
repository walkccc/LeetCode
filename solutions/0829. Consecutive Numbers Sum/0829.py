class Solution:
  def consecutiveNumbersSum(self, N: int) -> int:
    ans = 0
    i = 1
    triangleNum = 1

    while triangleNum <= N:
      if (N - triangleNum) % i == 0:
        ans += 1
      i += 1
      triangleNum += i

    return ans
