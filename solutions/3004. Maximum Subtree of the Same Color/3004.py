class Solution:
  def maximumSubtreeSize(
      self,
      edges: list[list[int]],
      colors: list[int],
  ) -> int:
    ans = 1
    tree = [[] for _ in range(len(colors))]

    for u, v in edges:
      tree[u].append(v)

    def dfs(u: int) -> int:
      """
      Returns the size of subtree of u if every node in the subtree has the same
      color. Otherwise, returns -1.
      """
      nonlocal ans
      res = 1
      for v in tree[u]:
        if colors[v] != colors[u]:
          res = -1
        # If any node in the subtree of v has a different color, the result of
        # the subtree of u will be -1 as well.
        subtreeSize = dfs(v)
        if subtreeSize == -1:
          res = -1
        elif res != -1:
          res += subtreeSize
      ans = max(ans, res)
      return res

    dfs(0)
    return ans
