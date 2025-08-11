class Solution:
  def smallestCommonElement(self, mat: list[list[int]]) -> int:
    MAX = 10000
    count = [0] * (MAX + 1)

    for row in mat:
      for a in row:
        count[a] += 1
        if count[a] == len(mat):
          return a

    return -1
