class Solution:
  def minMeetingRooms(self, intervals: list[list[int]]) -> int:
    minHeap = []  # Store the end times of each room.

    for start, end in sorted(intervals):
      # There's no overlap, so we can reuse the same room.
      if minHeap and start >= minHeap[0]:
        heapq.heappop(minHeap)
      heapq.heappush(minHeap, end)

    return len(minHeap)
