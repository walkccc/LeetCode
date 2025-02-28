class Solution:
  def mincostTickets(self, days: list[int], costs: list[int]) -> int:
    ans = 0
    last7 = collections.deque()
    last30 = collections.deque()

    for day in days:
      while last7 and last7[0][0] + 7 <= day:
        last7.popleft()
      while last30 and last30[0][0] + 30 <= day:
        last30.popleft()
      last7.append([day, ans + costs[1]])
      last30.append([day, ans + costs[2]])
      ans = min(ans + costs[0], last7[0][1], last30[0][1])

    return ans
