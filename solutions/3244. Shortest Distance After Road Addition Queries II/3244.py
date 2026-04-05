class Solution:
  def shortestDistanceAfterQueries(
      self,
      n: int,
      queries: list[list[int]],
  ) -> list[int]:
    ans = []
    nodeToFarthestNode = {i: i + 1 for i in range(n - 1)}

    for u, v in queries:
      # If `u` exists in the map and `v` is farther than the current farthest
      # node for `u`, we need to update the map and remove intermediate nodes.
      if u in nodeToFarthestNode and nodeToFarthestNode[u] < v:
        node = nodeToFarthestNode[u]
        while node < v:
          node = nodeToFarthestNode.pop(node)
        nodeToFarthestNode[u] = v
      ans.append(len(nodeToFarthestNode))

    return ans
