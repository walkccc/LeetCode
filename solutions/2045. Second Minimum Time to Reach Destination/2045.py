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
    # minTime[u][0] := the first minimum time to reach the node u
    # minTime[u][1] := the second minimum time to reach the node u
    minTime = [[math.inf] * 2 for _ in range(n + 1)]
    minTime[1][0] = 0

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    while q:
      u, prevTime = q.popleft()
      # Start from green.
      # If `numChangeSignal` is odd, now red.
      # If numChangeSignal is even -> now gree
      numChangeSignal = prevTime // change
      waitTime = (0 if numChangeSignal % 2 == 0
                  else change - (prevTime % change))
      newTime = prevTime + waitTime + time
      for v in graph[u]:
        if newTime < minTime[v][0]:
          minTime[v][0] = newTime
          q.append((v, newTime))
        elif minTime[v][0] < newTime < minTime[v][1]:
          if v == n:
            return newTime
          minTime[v][1] = newTime
          q.append((v, newTime))
