from enum import Enum


class State(Enum):
  INIT = 0
  VISITING = 1
  VISITED = 2


class Solution:
  def supersequences(self, words: list[str]) -> list[list[int]]:
    ans = []
    edges = [(string.ascii_lowercase.index(words[0]),
              string.ascii_lowercase.index(words[1]))
             for words in words]
    nodes = sorted({u for u, _ in edges} | {v for _, v in edges})
    letterToIndex = {letter: i for i, letter in enumerate(nodes)}
    graph = [[] for _ in range(len(nodes))]

    for u, v in edges:
      graph[letterToIndex[u]].append(letterToIndex[v])

    for doubledSubset in self._getMinimumSubsets(graph):
      freq = [0] * 26
      for letter in nodes:
        freq[letter] = 1
      for index in doubledSubset:
        freq[nodes[index]] = 2
      ans.append(freq)

    return ans

  def _getMinimumSubsets(self, graph: list[list[int]]) -> list[tuple[int]]:
    """
    Returns a list of the minimum subsets of nodes that do not create a cycle
    when skipped.
    """
    n = len(graph)
    for subsetSize in range(n + 1):
      doubleSubsets = []
      for doubledSubset in itertools.combinations(range(n), subsetSize):
        if not self._hasCycleSkipping(graph, set(doubledSubset)):
          doubleSubsets.append(doubledSubset)
      if doubleSubsets:
        return doubleSubsets
    return []

  def _hasCycleSkipping(
      self,
      graph: list[list[int]],
      doubledSubset: set[int]
  ) -> bool:
    """
    Returns True if there is a cycle in the `graph` when skipping any edges
    whose both endpoints are in `doubledSubset`.
    """
    states = [State.INIT] * len(graph)

    def hasCycle(u: int) -> bool:
      if states[u] == State.VISITING:
        return True
      if states[u] == State.VISITED:
        return False
      states[u] = State.VISITING
      if u not in doubledSubset:
        for v in graph[u]:
          if v in doubledSubset:
            continue
          if hasCycle(v):
            return True
      states[u] = State.VISITED
      return False

    return any(hasCycle(i) for i in range(len(graph)))
