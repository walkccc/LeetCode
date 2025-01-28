class Solution:
  def diagonalSort(self, mat: list[list[int]]) -> list[list[int]]:
    m = len(mat)
    n = len(mat[0])

    count = collections.defaultdict(list)

    for i in range(m):
      for j in range(n):
        count[i - j].append(mat[i][j])

    for value in count.values():
      value.sort(reverse=1)

    for i in range(m):
      for j in range(n):
        mat[i][j] = count[i - j].pop()

    return mat
