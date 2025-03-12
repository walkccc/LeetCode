class Solution:
  def treeQueries(self, root: TreeNode | None, queries: list[int]) -> list[int]:
    @lru_cache(None)
    def height(root: TreeNode | None) -> int:
      if not root:
        return 0
      return 1 + max(height(root.left), height(root.right))

    # valToMaxHeight[val] := the maximum height without the node with `val`
    valToMaxHeight = {}

    # maxHeight := the maximum height without the current node `root`
    def dfs(root: TreeNode | None, depth: int, maxHeight: int) -> None:
      if not root:
        return
      valToMaxHeight[root.val] = maxHeight
      dfs(root.left, depth + 1, max(maxHeight, depth + height(root.right)))
      dfs(root.right, depth + 1, max(maxHeight, depth + height(root.left)))

    dfs(root, 0, 0)
    return [valToMaxHeight[query] for query in queries]
