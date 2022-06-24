from enum import Enum


class State(Enum):
  INIT = 0
  VISITING = 1
  VISITED = 2


class Solution:
  def maximumInvitations(self, favorite: List[int]) -> int:
    n = len(favorite)
    sumComponentsLength = 0  # component: a -> b -> c <-> x <- y
    graph = [[] for _ in range(n)]
    inDegree = [0] * n
    maxChainLength = [1] * n

    # build graph
    for i, f in enumerate(favorite):
      graph[i].append(f)
      inDegree[f] += 1

    # topology
    q = deque([i for i, d in enumerate(inDegree) if d == 0])

    while q:
      u = q.popleft()
      for v in graph[u]:
        inDegree[v] -= 1
        if inDegree[v] == 0:
          q.append(v)
        maxChainLength[v] = max(maxChainLength[v], 1 + maxChainLength[u])

    for i in range(n):
      if favorite[favorite[i]] == i:
        # i <-> favorite[i] (cycle's length = 2)
        sumComponentsLength += maxChainLength[i] + maxChainLength[favorite[i]]

    maxCycleLength = 0  # cycle: a -> b -> c -> a
    parent = [-1] * n
    seen = set()
    state = [State.INIT] * n

    def findCycle(u: int) -> None:
      nonlocal maxCycleLength
      seen.add(u)
      state[u] = State.VISITING
      for v in graph[u]:
        if v not in seen:
          parent[v] = u
          findCycle(v)
        elif state[v] == State.VISITING:
          # find the cycle's length
          curr = u
          cycleLength = 1
          while curr != v:
            curr = parent[curr]
            cycleLength += 1
          maxCycleLength = max(maxCycleLength, cycleLength)
      state[u] = State.VISITED

    for i in range(n):
      if i not in seen:
        findCycle(i)

    return max(sumComponentsLength // 2, maxCycleLength)
