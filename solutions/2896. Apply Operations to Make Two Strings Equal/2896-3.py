class Solution:
  def minOperations(self, s1: str, s2: str, x: int) -> int:
    diffIndices = [i for i, (a, b) in enumerate(zip(s1, s2))
                   if a != b]
    if not diffIndices:
      return 0
    # It's impossible to make two strings equal if there are odd number of
    # differences.
    if len(diffIndices) & 1:
      return -1

    #         dp := the minimum cost to correct diffIndices[i:]
    #     dpNext := the minimum cost to correct diffIndices[i + 1:]
    # dpNextNext := the minimum cost to correct diffIndices[i + 2:]
    dpNext = x / 2
    dpNextNext = 0

    for i in reversed(range(len(diffIndices) - 1)):
      dp = min(dpNext + x / 2,
               dpNextNext + diffIndices[i + 1] - diffIndices[i])
      dpNextNext = dpNext
      dpNext = dp

    return int(dp)
