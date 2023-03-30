class Solution:
  def minMeetingRooms(self, intervals: List[List[int]]) -> int:
    minHeap = []  # Store end times of each room.

    for start, end in sorted(intervals):
      # No overlap, we can reuse the same room.
      if minHeap and start >= minHeap[0]:
        heapq.heappop(minHeap)
      heapq.heappush(minHeap, end)

    return len(minHeap)
