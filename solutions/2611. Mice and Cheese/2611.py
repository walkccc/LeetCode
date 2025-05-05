class Solution:
  def miceAndCheese(
      self,
      reward1: list[int],
      reward2: list[int],
      k: int,
  ) -> int:
    return (sum(reward2) +
            sum(heapq.nlargest(k, (a - b for a, b in zip(reward1, reward2)))))
