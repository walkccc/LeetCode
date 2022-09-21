class Solution:
  def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
    ans = -math.inf
    q = deque()  # (y - x, x) max queue

    for x, y in points:
      # remove invalid points, xj - xi > k
      while q and x - q[0][1] > k:
        q.popleft()
      if q:
        ans = max(ans, x + y + q[0][0])
      # remove points that contribute less value and have bigger x
      while q and y - x >= q[-1][0]:
        q.pop()
      q.append((y - x, x))

    return ans
