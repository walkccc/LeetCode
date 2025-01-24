class Solution:
  # Similar to 253. Meeting Rooms II
  def minGroups(self, intervals: list[list[int]]) -> int:
    minHeap = []  # Stores `right`s.

    for left, right in sorted(intervals):
      # There's no overlap, so we can reuse the same group.
      if minHeap and left > minHeap[0]:
        heapq.heappop(minHeap)
      heapq.heappush(minHeap, right)

    return len(minHeap)
