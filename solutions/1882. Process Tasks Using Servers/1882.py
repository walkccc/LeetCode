class Solution:
  def assignTasks(self, servers: list[int], tasks: list[int]) -> list[int]:
    ans = []
    free = []  # (weight, index, freeTime)
    used = []  # (freeTime, weight, index)

    for i, weight in enumerate(servers):
      heapq.heappush(free, (weight, i, 0))

    for i, executionTime in enumerate(tasks):  # i := the current time
      # Poll all servers that'll be free at time i.
      while used and used[0][0] <= i:
        curr = heapq.heappop(used)
        heapq.heappush(free, (curr[1], curr[2], curr[0]))
      if free:
        curr = heapq.heappop(free)
        ans.append(curr[1])
        heapq.heappush(used, (i + executionTime, curr[0], curr[1]))
      else:
        curr = heapq.heappop(used)
        ans.append(curr[2])
        heapq.heappush(used, (curr[0] + executionTime, curr[1], curr[2]))

    return ans
