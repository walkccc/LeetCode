class Solution:
  def winningPlayerCount(self, n: int, pick: List[List[int]]) -> int:
    counts = [collections.Counter() for _ in range(n)]
    for player, color in pick:
      counts[player][color] += 1
    return sum(max(count.values(), default=0) > i
               for i, count in enumerate(counts))
