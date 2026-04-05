class Solution:
  def findSubtreeSizes(self, parent: list[int], s: str) -> list[int]:
    n = len(parent)
    ans = [0] * n
    newParent = parent.copy()
    tree = [[] for _ in range(n)]

    for i in range(1, n):
      closest = self._findClosestAncestor(i, parent, s)
      if closest != -1:
        newParent[i] = closest

    for i in range(1, n):
      tree[newParent[i]].append(i)

    self._dfs(tree, 0, ans)
    return ans

  def _findClosestAncestor(self, u: int, parent: list[int], s: str) -> int:
    """
    Returns the closest ancestor of node `u` that has the same value as `u`.
    """
    curr = parent[u]
    while curr != -1:
      if s[curr] == s[u]:
        return curr
      curr = parent[curr]
    return -1

  def _dfs(self, tree: list[list[int]], u: int, ans: list[int]) -> int:
    sz = 1
    for v in tree[u]:
      sz += self._dfs(tree, v, ans)
    ans[u] = sz
    return sz
