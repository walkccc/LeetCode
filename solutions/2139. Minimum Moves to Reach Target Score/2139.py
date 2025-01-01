class Solution:
  def minMoves(self, target: int, maxDoubles: int) -> int:
    steps = 0

    while target > 1 and maxDoubles:
      if target % 2 == 1:
        target -= 1
      else:
        target //= 2
        maxDoubles -= 1
      steps += 1

    return steps + target - 1
