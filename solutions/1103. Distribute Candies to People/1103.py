class Solution:
  def distributeCandies(self, candies: int, n: int) -> list[int]:
    ans = [0] * n
    rows = int((-n + (n**2 + 8 * n**2 * candies)**0.5) / (2 * n**2))
    accumN = rows * (rows - 1) * n // 2

    for i in range(n):
      ans[i] = accumN + rows * (i + 1)

    givenCandies = (n**2 * rows**2 + n * rows) // 2
    candies -= givenCandies
    lastGiven = rows * n
    i = 0

    while candies > 0:
      lastGiven += 1
      actualGiven = min(lastGiven, candies)
      candies -= actualGiven
      ans[i] += actualGiven
      i += 1

    return ans
