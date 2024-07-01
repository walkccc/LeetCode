class Solution:
  def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
    ans = -math.inf
    maxQ = collections.deque()  # (y - x, x)

    for x, y in points:
      # Remove the invalid points, xj - xi > k
      while maxQ and x - maxQ[0][1] > k:
        maxQ.popleft()
      if maxQ:
        ans = max(ans, x + y + maxQ[0][0])
      # Remove the points that contribute less value and have a bigger x.
      while maxQ and y - x >= maxQ[-1][0]:
        maxQ.pop()
      maxQ.append((y - x, x))

    return ans
