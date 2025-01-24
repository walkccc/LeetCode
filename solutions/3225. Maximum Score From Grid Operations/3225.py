class Solution:
  def maximumScore(self, grid: list[list[int]]) -> int:
    n = len(grid)
    # prefix[j][i] := the sum of the first i elements in the j-th column
    prefix = [[0] * (n + 1) for _ in range(n)]
    # prevPick[i] := the maximum score up to the previous column, where the
    # bottommost selected element in the previous column is in row (i - 1)
    prevPick = [0] * (n + 1)
    # prevSkip[i] := the maximum score up to the previous column, where the
    # bottommost selected element in the column before the previous one is in
    # row (i - 1)
    prevSkip = [0] * (n + 1)

    for j in range(n):
      for i in range(n):
        prefix[j][i + 1] = prefix[j][i] + grid[i][j]

    for j in range(1, n):
      currPick = [0] * (n + 1)
      currSkip = [0] * (n + 1)
      # Consider all possible combinations of the number of current and
      # previous selected elements.
      for curr in range(n + 1):  # the number of current selected elements
        for prev in range(n + 1):  # the number of previous selected elements
          if curr > prev:
            # 1. The current bottom is deeper than the previous bottom.
            # Get the score of grid[prev..curr)[j - 1] for both pick and skip.
            score = prefix[j - 1][curr] - prefix[j - 1][prev]
            currPick[curr] = max(currPick[curr], prevSkip[prev] + score)
            currSkip[curr] = max(currSkip[curr], prevSkip[prev] + score)
          else:
            # 2. The previous bottom is deeper than the current bottom.
            # Get the score of grid[curr..prev)[j] for pick only.
            score = prefix[j][prev] - prefix[j][curr]
            currPick[curr] = max(currPick[curr], prevPick[prev] + score)
            currSkip[curr] = max(currSkip[curr], prevPick[prev])
      prevPick = currPick
      prevSkip = currSkip

    return max(prevPick)
