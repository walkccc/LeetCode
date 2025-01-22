from dataclasses import dataclass


@dataclass
class Node:
  node: int = 0  # the node number
  time: int = 0  # the time it got marked


class Last2:
  def __init__(self, last1: Node = Node(), last2: Node = Node()):
    self.last1 = last1  # the last marked node
    self.last2 = last2  # the second last marked node


class Solution:
  # Similar to 3241. Time Taken to Mark All Nodes
  def lastMarkedNodes(self, edges: list[list[int]]) -> list[int]:
    n = len(edges) + 1
    ans = [0] * n
    tree = [[] for _ in range(n)]
    # dp[i] := the last marked two nodes for subtree rooted at node i, where
    # each node contains the time it got marked
    dp = [Last2()] * n

    for u, v in edges:
      tree[u].append(v)
      tree[v].append(u)

    self._dfs(tree, 0, -1, dp)
    self._reroot(tree, 0, -1, Node(), dp, ans)
    return ans

  def _dfs(
      self,
      tree: list[list[int]],
      u: int,
      prev: int,
      dp: list[Last2]
  ) -> Node:
    """
    Performs a DFS traversal of the subtree rooted at node `u`, computes the
    time taken to mark all nodes in the subtree, records the last two marked
    nodes, and returns the last marked node.

    These values are used later in the rerooting process.
    """
    last1 = Node(u, 0)
    last2 = Node()
    for v in tree[u]:
      if v == prev:
        continue
      child = self._dfs(tree, v, u, dp)
      time = child.time + 1
      if time > last1.time:
        last2 = last1
        last1 = Node(child.node, time)
      elif time > last2.time:
        last2 = Node(child.node, time)
    dp[u] = Last2(last1, last2)
    return last1

  def _reroot(
      self,
      tree: list[list[int]],
      u: int,
      prev: int,
      last: Node,
      dp: list[list[int]],
      ans: list[int]
  ) -> None:
    """
    Reroots the tree at node `u` and updates the answer array, where `last`
    is the last marked node that doesn't go through `u`'s subtree.
    """
    ans[u] = last.node if last.time > dp[u].last1.time else dp[u].last1.node
    for v in tree[u]:
      if v == prev:
        continue
      newLast = Node(last.node, last.time + 1)
      if dp[u].last1.node == dp[v].last1.node:
        alternativeTime = 1 + dp[u].last2.time
        if alternativeTime > newLast.time:
          newLast = Node(dp[u].last2.node, alternativeTime)
      else:
        alternativeTime = 1 + dp[u].last1.time
        if alternativeTime > newLast.time:
          newLast = Node(dp[u].last1.node, alternativeTime)
      self._reroot(tree, v, u, newLast, dp, ans)
