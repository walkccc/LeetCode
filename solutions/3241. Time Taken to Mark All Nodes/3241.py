from dataclasses import dataclass


@dataclass
class Node:
  node: int = 0  # the node number
  time: int = 0  # the time taken to mark the entire subtree rooted at the node


class Top2:
  def __init__(self, top1: Node = Node(), top2: Node = Node()):
    # the direct child node, where the time taken to mark the entire subtree
    # rooted at the node is the maximum
    self.top1 = top1
    # the direct child node, where the time taken to mark the entire subtree
    # rooted at the node is the second maximum
    self.top2 = top2


class Solution:
  def timeTaken(self, edges: list[list[int]]) -> list[int]:
    n = len(edges) + 1
    ans = [0] * n
    tree = [[] for _ in range(n)]
    # dp[i] := the top two direct child nodes for subtree rooted at node i,
    # where each node contains the time taken to mark the entire subtree rooted
    # at the node itself
    dp = [Top2()] * n

    for u, v in edges:
      tree[u].append(v)
      tree[v].append(u)

    self._dfs(tree, 0, -1, dp)
    self._reroot(tree, 0, -1, 0, dp, ans)
    return ans

  def _getTime(self, u: int) -> int:
    """Returns the time taken to mark node u."""
    return 2 if u % 2 == 0 else 1

  def _dfs(
      self,
      tree: list[list[int]],
      u: int,
      prev: int,
      dp: list[Top2]
  ) -> int:
    """
    Performs a DFS traversal of the subtree rooted at node `u`, computes the
    time taken to mark all nodes in the subtree, records the top two direct
    child nodes, where the time taken to mark the subtree rooted at each of the
    child nodes is maximized, and returns the top child node.

    These values are used later in the rerooting process.
    """
    top1 = Node()
    top2 = Node()
    for v in tree[u]:
      if v == prev:
        continue
      time = self._dfs(tree, v, u, dp) + self._getTime(v)
      if time >= top1.time:
        top2 = top1
        top1 = Node(v, time)
      elif time > top2.time:
        top2 = Node(v, time)
    dp[u] = Top2(top1, top2)
    return top1.time

  def _reroot(
      self,
      tree: list[list[int]],
      u: int,
      prev: int,
      maxTime: int,
      dp: list[Top2],
      ans: list[int]
  ) -> None:
    """
    Reroots the tree at node `u` and updates the answer array, where `maxTime`
    is the longest path that doesn't go through `u`'s subtree.
    """
    ans[u] = max(maxTime, dp[u].top1.time)

    for v in tree[u]:
      if v == prev:
        continue
      newMaxTime = self._getTime(u) + max(
          maxTime,
          dp[u].top2.time if dp[u].top1.node == v else dp[u].top1.time
      )
      self._reroot(tree, v, u, newMaxTime, dp, ans)
