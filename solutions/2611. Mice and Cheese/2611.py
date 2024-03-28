class Solution:
  def miceAndCheese(self, reward1: List[int], reward2: List[int], k: int) -> int:
    return sum(reward2) + sum(heapq.nlargest(k, (a - b for a, b in zip(reward1, reward2))))
