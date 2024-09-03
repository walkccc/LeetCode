class Solution:
  def secondMinimum(
      self,
      n: int,
      edges: list[list[int]],
      time: int,
      change: int,
  ) -> int:
    graph = [[] for _ in range(n + 1)]
    q = collections.deque([(1, 0)])
    # minTime[i][0] := the first minimum time to reach the node i
    # minTime[i][1] := the second minimum time to reach the node i
    minTime = [[math.inf] * 2 for _ in range(n + 1)]
    minTime[1][0] = 0

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    while q:
      i, prevTime = q.popleft()
      # Start from green.
      # If `numChangeSignal` is odd, now red.
      # If numChangeSignal is even -> now gree
      numChangeSignal = prevTime // change
      waitTime = (0 if numChangeSignal % 2 == 0
                  else change - (prevTime % change))
      newTime = prevTime + waitTime + time
      for j in graph[i]:
        if newTime < minTime[j][0]:
          minTime[j][0] = newTime
          q.append((j, newTime))
        elif minTime[j][0] < newTime < minTime[j][1]:
          if j == n:
            return newTime
          minTime[j][1] = newTime
          q.append((j, newTime))
