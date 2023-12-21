class Solution:
  # Similar to 253. Meeting Rooms II
  def minGroups(self, intervals: List[List[int]]) -> int:
    minHeap = []  # Stores the `right`s.

    for left, right in sorted(intervals):
      if minHeap and left > minHeap[0]:
        # There is no overlaps, so we can reuse the same group.
        heapq.heappop(minHeap)
      heapq.heappush(minHeap, right)

    return len(minHeap)
