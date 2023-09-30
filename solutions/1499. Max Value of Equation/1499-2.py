class Solution:
  def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
    ans = -math.inf
    dq = collections.deque()  # (y - x, x) max queue

    for x, y in points:
      # Remove invalid points, xj - xi > k
      while dq and x - dq[0][1] > k:
        dq.popleft()
      if dq:
        ans = max(ans, x + y + dq[0][0])
      # Remove points that contribute less value and have bigger x
      while dq and y - x >= dq[-1][0]:
        dq.pop()
      dq.append((y - x, x))

    return ans
