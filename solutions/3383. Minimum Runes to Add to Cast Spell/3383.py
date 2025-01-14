class Solution:
  def minRunesToAdd(
      self,
      n: int,
      crystals: list[int],
      flowFrom: list[int],
      flowTo: list[int]
  ) -> int:
    graph = [[] for _ in range(n)]
    reversedGraph = [[] for _ in range(n)]

    for u, v in zip(flowFrom, flowTo):
      graph[u].append(v)
      reversedGraph[v].append(u)

    # Identify Strongly Connected Components (SCC) using Kosaraju's Algorithm.
    seen = set()
    orderStack = []
    componentIds = [-1] * n
    componentCount = 0

    for i in range(n):
      if i not in seen:
        self._kosaraju(graph, i, seen, orderStack)

    while orderStack:
      u = orderStack.pop()
      if componentIds[u] == -1:
        self._identifySCC(reversedGraph, u, componentIds, componentCount)
        componentCount += 1

    # Track crystal-containing components and inter-component edges.
    hasCrystal = [False] * componentCount
    hasInterComponentEdge = [False] * componentCount

    for u in crystals:
      hasCrystal[componentIds[u]] = True

    for u, v in zip(flowFrom, flowTo):
      id1 = componentIds[u]
      id2 = componentIds[v]
      if id1 != id2:  # Edge is inter-component.
        hasInterComponentEdge[id2] = True

    return sum(not hasCrystal[i] and not hasInterComponentEdge[i]
               for i in range(componentCount))

  def _kosaraju(
      self,
      graph: list[list[int]],
      u: int,
      seen: set[int],
      orderStack: list
  ) -> None:
    """Creates a topological order stack using Kosaraju's Algorithm."""
    seen.add(u)
    for v in graph[u]:
      if v not in seen:
        self._kosaraju(graph, v, seen, orderStack)
    orderStack.append(u)

  def _identifySCC(
      self,
      reversedGraph: list[list[int]],
      u: int,
      componentIds: list[int],
      componentId: int
  ) -> None:
    """Assigns component IDs during SCC identification in the second DFS."""
    if componentIds[u] != -1:
      return
    componentIds[u] = componentId
    for v in reversedGraph[u]:
      if componentIds[v] == -1:
        self._identifySCC(reversedGraph, v, componentIds, componentId)
