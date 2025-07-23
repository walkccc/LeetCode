class Solution:
  def pathExistenceQueries(
      self,
      n: int,
      nums: list[int],
      maxDiff: int,
      queries: list[list[int]],
  ) -> list[int]:
    sortedNumAndIndexes = sorted((num, i) for i, num in enumerate(nums))
    sortedNums = [num for num, _ in sortedNumAndIndexes]
    indexMap = {originalIndex: sortedIndex for sortedIndex,
                (_, originalIndex) in enumerate(sortedNumAndIndexes)}
    maxLevel = n.bit_length() + 1
    # jump[i][j] is the index of the j-th ancestor of i
    jump = [[0] * maxLevel for _ in range(n)]

    right = 0
    for i in range(n):
      while right + 1 < n and sortedNums[right + 1] - sortedNums[i] <= maxDiff:
        right += 1
      jump[i][0] = right

    for level in range(1, maxLevel):
      for i in range(n):
        prevJump = jump[i][level - 1]
        jump[i][level] = jump[prevJump][level - 1]

    def minJumps(start: int, end: int, level: int) -> int:
      """
      Returns the minimum number of jumps from `start` to `end` using binary
      lifting.
      """
      if start == end:
        return 0
      if jump[start][0] >= end:
        return 1
      if jump[start][level] < end:
        return math.inf
      for j in range(level, -1, -1):
        if jump[start][j] < end:
          break
      return (1 << j) + minJumps(jump[start][j], end, j)

    def minDist(u: int, v: int) -> int:
      uIndex = indexMap[u]
      vIndex = indexMap[v]
      start = min(uIndex, vIndex)
      end = max(uIndex, vIndex)
      res = minJumps(start, end, maxLevel - 1)
      return res if res < math.inf else -1

    return [minDist(u, v) for u, v in queries]
