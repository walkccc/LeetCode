class Solution:
  # very similar to 253. Meeting Rooms II
  def minGroups(self, intervals: List[List[int]]) -> int:
    minHeap = []  # store `right`s

    for left, right in sorted(intervals):
      if minHeap and left > minHeap[0]:
        heapq.heappop(minHeap)
      heapq.heappush(minHeap, right)

    return len(minHeap)
