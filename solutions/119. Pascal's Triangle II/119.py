class Solution:
  def getRow(self, rowIndex: int) -> list[int]:
    ans = [1] * (rowIndex + 1)

    for i in range(2, rowIndex + 1):
      for j in range(1, i):
        ans[i - j] += ans[i - j - 1]

    return ans
