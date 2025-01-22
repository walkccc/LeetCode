class Solution:
  def rowAndMaximumOnes(self, mat: list[list[int]]) -> list[int]:
    ans = [0, 0]

    for i, row in enumerate(mat):
      ones = row.count(1)
      if ones > ans[1]:
        ans[0] = i
        ans[1] = ones

    return ans
