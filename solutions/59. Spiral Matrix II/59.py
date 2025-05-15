class Solution:
  def generateMatrix(self, n: int) -> list[list[int]]:
    ans = [[0] * n for _ in range(n)]
    count = 1

    for mn in range(n // 2):
      mx = n - mn - 1
      for i in range(mn, mx):
        ans[mn][i] = count
        count += 1
      for i in range(mn, mx):
        ans[i][mx] = count
        count += 1
      for i in range(mx, mn, -1):
        ans[mx][i] = count
        count += 1
      for i in range(mx, mn, -1):
        ans[i][mn] = count
        count += 1

    if n % 2 == 1:
      ans[n // 2][n // 2] = count

    return ans
