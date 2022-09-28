class Solution:
  def maxEvents(self, events: List[List[int]]) -> int:
    ans = 0
    minHeap = []
    i = 0  # events' index

    events.sort(key=lambda x: x[0])

    while minHeap or i < len(events):
      # if no events are available to attend today,
      # let time flies to the next available event
      if not minHeap:
        d = events[i][0]
      # all events starting from today are newly available
      while i < len(events) and events[i][0] == d:
        heapq.heappush(minHeap, events[i][1])
        i += 1
      # greedily attend the event that'll end the earliest
      # because it has higher chance can't be attended in the future
      heapq.heappop(minHeap)
      ans += 1
      d += 1
      # pop events that can't be attended
      while minHeap and minHeap[0] < d:
        heapq.heappop(minHeap)

    return ans
