class Solution:
  def minMeetingRooms(self, intervals: List[List[int]]) -> int:
    if not intervals:
      return 0

    # store end times of each room
    pq = []

    intervals.sort()

    for start, end in intervals:
      if pq and start >= pq[0]:
        heapq.heappop(pq)
      heapq.heappush(pq, end)

    return len(pq)
