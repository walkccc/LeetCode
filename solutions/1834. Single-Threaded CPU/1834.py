class Solution:
  def getOrder(self, tasks: list[list[int]]) -> list[int]:
    n = len(tasks)
    A = [[*task, i] for i, task in enumerate(tasks)]
    ans = []
    minHeap = []
    i = 0  # tasks' index
    time = 0  # the current time

    A.sort()

    while i < n or minHeap:
      if not minHeap:
        time = max(time, A[i][0])
      while i < n and time >= A[i][0]:
        heapq.heappush(minHeap, (A[i][1], A[i][2]))
        i += 1
      procTime, index = heapq.heappop(minHeap)
      time += procTime
      ans.append(index)

    return ans
