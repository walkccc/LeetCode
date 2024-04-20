class Solution:
  def numMovesStonesII(self, stones: List[int]) -> List[int]:
    n = len(stones)
    minMoves = n

    stones.sort()

    l = 0
    for r, stone in enumerate(stones):
      while stone - stones[l] + 1 > n:
        l += 1
      alreadyStored = r - l + 1
      if alreadyStored == n - 1 and stone - stones[l] + 1 == n - 1:
        minMoves = 2
      else:
        minMoves = min(minMoves, n - alreadyStored)

    return [minMoves, max(stones[n - 1] - stones[1] - n + 2, stones[n - 2] - stones[0] - n + 2)]
