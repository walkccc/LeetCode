class Solution:
  def minMeetingRooms(self, intervals: List[List[int]]) -> int:
    minHeap = []  # store end times of each room

    for start, end in sorted(intervals):
      if minHeap and start >= minHeap[0]:
        heapq.heappop(minHeap)
      heapq.heappush(minHeap, end)

    return len(minHeap)
