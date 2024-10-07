from dataclasses import dataclass


@dataclass
class T:
  node: int = -1  # the node number
  time: int = 0  # the time taken to reach this node


class Top2:
  def __init__(self, max1: T = T(-1, 0), max2: T = T(-1, 0)):
    self.max1 = max1  # the node with the maximum time
    self.max2 = max2  # the node with the second maximum time


class Solution:
  def timeTaken(self, edges: list[list[int]]) -> list[int]:
    n = len(edges) + 1
    ans = [0] * n
    tree = [[] for _ in range(n)]
    # dp[i] := the top two nodes with maximum times to mark all nodes in the
    # subtree rooted at node i
    dp = [Top2()] * n

    for u, v in edges:
      tree[u].append(v)
      tree[v].append(u)

    def getTime(u: int) -> int:
      """Returns the time taken to mark node u."""
      return 2 if u % 2 == 0 else 1

    def dfs(u: int, prev: int) -> int:
      """
      Performs a DFS traversal of the tree, computing the maximum time to mark
      all nodes in the subtree rooted at node u.

      This function calculates and stores the top two maximum times for each
      node's subtree. These values are used later in the rerooting process.
      """
      max1 = T()
      max2 = T()
      for v in tree[u]:
        if v == prev:
          continue
        time = dfs(v, u) + getTime(v)
        if time >= max1.time:
          max2 = max1
          max1 = T(v, time)
        elif time > max2.time:
          max2 = T(v, time)
      dp[u] = Top2(max1, max2)
      return max1.time

    dfs(0, -1)

    def reroot(u: int, prev: int, maxTime) -> None:
      """
      Reroots the tree at node `u` and updates the answer array, where `maxTime`
      is the longest path that doesn't go through `u`'s subtree.
      """
      ans[u] = max(maxTime, dp[u].max1.time)

      for v in tree[u]:
        if v == prev:
          continue
        newMaxTime = getTime(u) + max(
            maxTime,
            dp[u].max2.time if dp[u].max1.node == v else dp[u].max1.time
        )
        reroot(v, u, newMaxTime)

    reroot(0, -1, 0)
    return ans
