class MedianFinder:
  def __init__(self):
    self.maxHeap = []
    self.minHeap = []

  def addNum(self, num: int) -> None:
    if not self.maxHeap or num <= -self.maxHeap[0]:
      heapq.heappush(self.maxHeap, -num)
    else:
      heapq.heappush(self.minHeap, num)

    # Balance the two heaps s.t.
    # |maxHeap| >= |minHeap| and |maxHeap| - |minHeap| <= 1.
    if len(self.maxHeap) < len(self.minHeap):
      heapq.heappush(self.maxHeap, -heapq.heappop(self.minHeap))
    elif len(self.maxHeap) - len(self.minHeap) > 1:
      heapq.heappush(self.minHeap, -heapq.heappop(self.maxHeap))

  def findMedian(self) -> float:
    if len(self.maxHeap) == len(self.minHeap):
      return (-self.maxHeap[0] + self.minHeap[0]) / 2.0
    return -self.maxHeap[0]
