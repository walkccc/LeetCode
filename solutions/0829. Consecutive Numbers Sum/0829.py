class Solution:
  def consecutiveNumbersSum(self, n: int) -> int:
    ans = 0
    i = 1
    triangleNum = 1
    while triangleNum <= n:
      if (n - triangleNum) % i == 0:
        ans += 1
      i += 1
      triangleNum += i
    return ans
