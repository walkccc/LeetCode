class Solution:
  def largestSubmatrix(self, matrix: List[List[int]]) -> int:
    ans = 0
    hist = [0] * len(matrix[0])

    for row in matrix:
      # Accumulate the histogram if possible.
      for i, num in enumerate(row):
        hist[i] = 0 if num == 0 else hist[i] + 1

      # Get the sorted histogram.
      sortedHist = sorted(hist)

      # Greedily calculate the answer.
      for i, h in enumerate(sortedHist):
        ans = max(ans, h * (len(row) - i))

    return ans
