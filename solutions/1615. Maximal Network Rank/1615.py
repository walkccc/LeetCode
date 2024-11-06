class Solution:
  def maximalNetworkRank(self, n: int, roads: list[list[int]]) -> int:
    degrees = [0] * n

    for u, v in roads:
      degrees[u] += 1
      degrees[v] += 1

    # Find the first maximum and the second maximum degrees.
    maxDegree1 = 0
    maxDegree2 = 0
    for degree in degrees:
      if degree > maxDegree1:
        maxDegree2 = maxDegree1
        maxDegree1 = degree
      elif degree > maxDegree2:
        maxDegree2 = degree

    # There can be multiple nodes with `maxDegree1` or `maxDegree2`.
    # Find the counts of such nodes.
    countMaxDegree1 = 0
    countMaxDegree2 = 0
    for degree in degrees:
      if degree == maxDegree1:
        countMaxDegree1 += 1
      elif degree == maxDegree2:
        countMaxDegree2 += 1

    if countMaxDegree1 == 1:
      # 1. If there is only one node with degree = `maxDegree1`, then we'll
      # need to use the node with degree = `maxDegree2`. The answer in general
      # will be (maxDegree1 + maxDegree2), but if the two nodes that we're
      # considering are connected, then we'll have to subtract 1.
      edgeCount = (self._getEdgeCount(roads, degrees, maxDegree1, maxDegree2) +
                   self._getEdgeCount(roads, degrees, maxDegree2, maxDegree1))
      return maxDegree1 + maxDegree2 - (countMaxDegree2 == edgeCount)
    else:
      # 2. If there are more than one node with degree = `maxDegree1`, then we
      # can consider `maxDegree1` twice, and we don't need to use `maxDegree2`.
      # The answer in general will be 2 * maxDegree1, but if the two nodes that
      # we're considering are connected, then we'll have to subtract 1.
      edgeCount = self._getEdgeCount(roads, degrees, maxDegree1, maxDegree1)
      maxPossibleEdgeCount = countMaxDegree1 * (countMaxDegree1 - 1) // 2
      return 2 * maxDegree1 - (maxPossibleEdgeCount == edgeCount)

  def _getEdgeCount(
      self,
      roads: list[list[int]],
      degrees: list[int],
      degreeU: int, degreeV: int,
  ) -> int:
    """
    Returns the number of edges (u, v) where degress[u] == degreeU and
    degrees[v] == degreeV.
    """
    edgeCount = 0
    for u, v in roads:
      if degrees[u] == degreeU and degrees[v] == degreeV:
        edgeCount += 1
    return edgeCount
