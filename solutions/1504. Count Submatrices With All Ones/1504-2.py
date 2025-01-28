class Solution:
  def numSubmat(self, mat: list[list[int]]) -> int:
    ans = 0
    hist = [0] * len(mat[0])

    for row in mat:
      for i, num in enumerate(row):
        hist[i] = 0 if num == 0 else hist[i] + 1
      ans += self._count(hist)

    return ans

  def _count(self, hist: list[int]) -> int:
    # submatrices[i] := the number of submatrices, where the i-th column is the
    # right border
    submatrices = [0] * len(hist)
    stack = []

    for i, h in enumerate(hist):
      while stack and hist[stack[-1]] >= h:
        stack.pop()
      if stack:
        prevIndex = stack[-1]
        submatrices[i] = submatrices[prevIndex] + h * (i - prevIndex)
      else:
        submatrices[i] = h * (i + 1)
      stack.append(i)

    return sum(submatrices)
