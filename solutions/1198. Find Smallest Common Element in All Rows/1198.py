class Solution:
  def smallestCommonElement(self, mat: List[List[int]]) -> int:
    kMax = 10000
    count = [0] * (kMax + 1)

    for row in mat:
      for a in row:
        count[a] += 1
        if count[a] == len(mat):
          return a

    return -1
