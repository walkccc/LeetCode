class SmallestInfiniteSet:
  def __init__(self):
    self.mini = 1
    self.heap = []

  def popSmallest(self) -> int:
    if self.heap:
      return heapq.heappop(self.heap)
    self.mini += 1
    return self.mini - 1

  def addBack(self, num: int) -> None:
    if num < self.mini and num not in self.heap:
      heapq.heappush(self.heap, num)